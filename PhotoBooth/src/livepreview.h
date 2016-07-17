#ifndef LIVEPREVIEW_H
#define LIVEPREVIEW_H

/**

The live preview of the camera stream is the main part of the GUI.
In this class the whole communication with the camera is handled.
When all images are taken and sent to the printer, the live preview also displays the final image.

**/

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <gphoto2/gphoto2.h>
#include <opencv2/opencv.hpp>



class LivePreview : public QGraphicsView {

    Q_OBJECT
    public:
        LivePreview(QWidget* parent);
        ~LivePreview(); //destructor to disconnect from the camera properly
        cv::Mat capture_image_and_save(int image_number); //take one image, save and return it

        void display_img_for_sec(cv::Mat image,int sec); //display an image for sec seconds
        void restart(); //restart the livepreview after the final image has been displayed for sec seconds
    public slots:
        void update_preview(); //display a new frame in the live preview
        void unblock_timer(); //unblocks the timer after the final image has been displayed
    signals:
        void restart_sig(); //restarts live preview

    private:


        QGraphicsScene * scene;
        QPixmap frame;
        QGraphicsPixmapItem * frame_item;
        QGraphicsPixmapItem * final_image_item;
        Camera * camera;
        GPContext * context;
        CameraFile * file;

        QTimer * timer; //on timeout() a new frame is fetched from the camera
        int retval;

};

#endif // LIVEPREVIEW_H
