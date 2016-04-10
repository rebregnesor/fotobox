#include <QImage>
#include "thumbnailview.h"



ThumbnailView::ThumbnailView(QWidget* parent):QListView(parent) {

    setViewMode(QListView::IconMode);
    setFlow(QListView::LeftToRight);
    model = new QStandardItemModel(4,1);
    setModel(model);
    setIconSize(QSize(300,200));

    resize(1250,500);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    initialize();
    setGridSize(QSize(width()/4,250));

}



void ThumbnailView::initialize() {

    for(int i=0; i<4; i++) {
           QIcon icon = QIcon("img/camera-photo.png");
           QStandardItem * item = new QStandardItem(icon, " ");
           delete model->item(i,0);
           model->setItem(i,0,item);
    }


}

void ThumbnailView::add_thumbnail(cv::Mat image, int image_number) {

    if (image_number == 0) {
        initialize();
    }
    
    QIcon icon = QIcon(QPixmap::fromImage(QImage((unsigned char *) image.data, image.cols, image.rows, QImage::Format_RGB888).rgbSwapped()));
    QStandardItem * item = new QStandardItem(icon, " ");
    delete model->item(image_number,0);
    model->setItem(image_number,0,item);
    update();
    
}
