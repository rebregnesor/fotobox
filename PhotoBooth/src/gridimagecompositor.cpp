#include "gridimagecompositor.h"
#include <QDebug>
GridImageCompositor::GridImageCompositor(int n_rows_,int n_cols_,double rel_frame_width_)
{
    n_rows=n_rows_;
    n_cols=n_cols_;
    rel_frame_width=rel_frame_width_;
}

cv::Mat GridImageCompositor::compose(std::vector<cv::Mat> &image_list, cv::Mat background){
    int width=image_list.at(0).cols;
    int height=image_list.at(0).rows;
    if (background.cols!=width || background.rows!=height) {
        qDebug() << background.cols;
        cv::resize(background,background,cv::Size(width,height));
    }
    if (image_list.size()>(unsigned int)n_rows*n_cols) {
        qDebug() << "too many images for chosen grid";
        return background;
    }
    int abs_frame_width=rel_frame_width*width;
    int image_width=( width-(n_cols+1)*abs_frame_width )/n_cols;
    int image_height=( height-(n_rows+1)*abs_frame_width )/n_rows;
    std::vector<std::pair<int,int> > positions;
    for (int i=0; i<n_rows; i++) {
        for (int j=0; j<n_cols; j++) {

            positions.push_back(std::make_pair((i+1)*abs_frame_width+i*image_width,(j+1)*abs_frame_width+j*image_height));
        }
    }
    for (unsigned int i=0; i<image_list.size();i++) {
       int x=positions.at(i).first;
       int y=positions.at(i).second;
       cv::resize(image_list.at(i),image_list.at(i),cv::Size(image_width,image_height));
       image_list.at(i).copyTo(background(cv::Rect(x,y,image_width,image_height)));
    }
       return background;
}
