#ifndef GRIDIMAGECOMPOSITOR_H
#define GRIDIMAGECOMPOSITOR_H

#include <opencv2/opencv.hpp>
#include <vector>
class GridImageCompositor
{
public:
    GridImageCompositor(int n_rows_, int n_cols_, double rel_frame_width_);
    cv::Mat compose(std::vector<cv::Mat> &image_list, cv::Mat background = cv::Mat(1, 1, CV_8UC3, cv::Scalar(255,255,255)));

private:
    int n_rows;
    int n_cols;
    double rel_frame_width;

};

#endif // GRIDIMAGECOMPOSITOR_H
