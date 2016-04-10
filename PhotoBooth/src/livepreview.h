#ifndef LIVEPREVIEW_H
#define LIVEPREVIEW_H

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
        ~LivePreview();
        cv::Mat capture_image_and_save(int image_number);

        void display_img_for_sec(cv::Mat image,int sec);
        void restart();
    public slots:
        void update_preview();
        void unblock_timer();
    signals:
        void restart_sig();

    private:


        QGraphicsScene * scene;
        QPixmap frame;
        QGraphicsPixmapItem * frame_item;
        QGraphicsPixmapItem * final_image_item;
        Camera * camera;
        GPContext * context;
        CameraFile * file;

        QTimer * timer;
        int retval;

};

#endif // LIVEPREVIEW_H
