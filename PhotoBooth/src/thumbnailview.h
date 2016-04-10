#ifndef THUMBNAILVIEW_H
#define THUMBNAILVIEW_H

#include <QListView>
#include <QStandardItemModel>

#include <opencv2/opencv.hpp>


class ThumbnailView : public QListView {

    Q_OBJECT
    public:
        ThumbnailView(QWidget* parent);
        void initialize();
        void add_thumbnail(cv::Mat image, int image_number);
     private:
        QStandardItemModel * model;


};

#endif // THUMBNAILVIEW_H
