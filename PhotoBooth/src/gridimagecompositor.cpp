#include "gridimagecompositor.h"
#include <QDebug>
GridImageCompositor::GridImageCompositor(int n_rows_,int n_cols_,double rel_frame_width_)
{
    n_rows=n_rows_; //set number of grid rows
    n_cols=n_cols_; //set number of grid columns
    rel_frame_width=rel_frame_width_; //set relative frame width
}

cv::Mat GridImageCompositor::compose(std::vector<cv::Mat> &image_list, cv::Mat background){
    int width=image_list.at(0).cols; //get image width in pixels
    int height=image_list.at(0).rows; //get image height in pixels
    if (background.cols!=width || background.rows!=height) { //check if background dimensions are right
        qDebug() << background.cols;
        cv::resize(background,background,cv::Size(width,height)); //resize background to image size
    }
    if (image_list.size()>(unsigned int)n_rows*n_cols) { //check if grid can handle the amount of images in image_list
        qDebug() << "too many images for chosen grid";
        return background; //if too many images, return the background only
    }
    int abs_frame_width=rel_frame_width*width; //calculate frame width in pixels
    int image_width=( width-(n_cols+1)*abs_frame_width )/n_cols; //calculate size of the photos placed on the grid
    int image_height=( height-(n_rows+1)*abs_frame_width )/n_rows;
    std::vector<std::pair<int,int> > positions; //store the positions of the photos
    for (int i=0; i<n_rows; i++) {
        for (int j=0; j<n_cols; j++) {

            positions.push_back(std::make_pair((i+1)*abs_frame_width+i*image_width,(j+1)*abs_frame_width+j*image_height)); //store the positions of the photos
        }
    }
    for (unsigned int i=0; i<image_list.size();i++) {
       int x=positions.at(i).first;
       int y=positions.at(i).second;
       cv::resize(image_list.at(i),image_list.at(i),cv::Size(image_width,image_height)); //resize photos and
       image_list.at(i).copyTo(background(cv::Rect(x,y,image_width,image_height)));      //place them on the background
    }
       return background; //if everything went fine, the background is returned
}
