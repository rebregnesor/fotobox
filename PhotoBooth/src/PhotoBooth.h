#ifndef PHOTOBOOTH_H
#define PHOTOBOOTH_H

#include <QMainWindow>
#include <vector>

#include "Countdown.h"
#include "thumbnailview.h"
#include "infopanel.h"
#include "livepreview.h"
#include "SerialPort.h"
#include "gridimagecompositor.h"
#include <opencv2/opencv.hpp>
class PhotoBooth : public QMainWindow
{
    Q_OBJECT
    public:
        PhotoBooth(void);
    public slots:
        void start_process(); //gets called whenever the button is pressed
        void take_snapshot(); //takes one picture and adds it to the image list
        void continue_process(); //gets called after first picture
        void combine_images();
        void update_credit(double coin); //update credit, when coin is inserted
        
    private:
        double credit;
        double price;
        int countdown_sec; //countdown time in seconds
        int n_copies; //number of photos that are going to be printed
        int n_images; //number of images that are placed on one photo
        int image_number; //current image
        InfoPanel * info_panel;
        LivePreview * live_preview;
        ThumbnailView * thumbnail_view;
        Countdown countdown;
        std::vector<cv::Mat> image_list;
        cv::Mat final_image;
        SerialPort arduino;
        GridImageCompositor gic;
};

#endif // PHOTOBOOTH_H
