#ifndef GRIDIMAGECOMPOSITOR_H
#define GRIDIMAGECOMPOSITOR_H

/**

  This class is able to arrange pictures stored as cv::Mat on an n by m grid.
  However, at this point only square grids work properly

**/

#include <opencv2/opencv.hpp>
#include <vector>
class GridImageCompositor
{
public:
    GridImageCompositor(int n_rows_, int n_cols_, double rel_frame_width_); //constructor used to set the grid dimension and the frame width (relative to picture width)
    cv::Mat compose(std::vector<cv::Mat> &image_list, cv::Mat background = cv::Mat(1, 1, CV_8UC3, cv::Scalar(255,255,255))); //places pictures stored in images_list on background and returns final image

private:
    int n_rows; //number of grid rows
    int n_cols; //number of grid columns
    double rel_frame_width; //relative frame width (relative to picture width)

};

#endif // GRIDIMAGECOMPOSITOR_H
