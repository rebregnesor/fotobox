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
        void start_process();
        void take_snapshot();
        void continue_process();
        void combine_images();
        void update_credit(double coin);
        
    private:
        double credit;
        double price;
        int countdown_sec;
        int n_copies;
        int n_images;
        int image_number;
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
