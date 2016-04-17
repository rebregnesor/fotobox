#include "livepreview.h"
#include <QDebug>

using namespace cv;

LivePreview::LivePreview(QWidget* parent):QGraphicsView(parent) {

    
    scene = new QGraphicsScene(this);
    setScene(scene);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_preview()));

    context = gp_context_new();
    gp_context_ref(context);
    gp_camera_new(&camera);
    retval = gp_camera_init(camera,context);
    if (retval!=GP_OK) {
        qDebug()<<"Camera init failed\n";
    } else {
    timer->start(300);
    }

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    frame_item = scene->addPixmap(QPixmap("img/camera-photo.png").scaledToHeight(this->height()));
}

LivePreview::~LivePreview() {

    retval = gp_camera_exit(camera,context);
    if (retval!=GP_OK) {
        qDebug()<<"exit failed";
    }


    qDebug()<<"Live Preview destroyed "<<retval;
}

void LivePreview::update_preview() {
    retval = gp_file_new(&file);
    retval = gp_camera_capture_preview(camera, file, context);
    const char * data;
    long unsigned int size;
    retval = gp_file_get_data_and_size(file,&data,&size);
    frame.loadFromData(QByteArray(data,size));
    scene->removeItem(frame_item);
    delete frame_item;
    frame_item = scene->addPixmap(frame.transformed(QTransform().scale(-1.3,1.3)));
    scene->update();
    gp_file_free(file);
}

Mat LivePreview::capture_image_and_save(int image_number) {
    timer->blockSignals(true);
    CameraFilePath file_path;
    CameraFile * cap_file;
    retval = gp_file_new(&cap_file);
    QString file_name = QString("img/img%1.jpg").arg(QString::number(image_number));

    retval = gp_camera_capture(camera,GP_CAPTURE_IMAGE, &file_path, context);
    retval = gp_camera_file_get(camera, file_path.folder,file_path.name, GP_FILE_TYPE_NORMAL, cap_file, context);

    const char * data;
    long unsigned int size;
    retval = gp_file_get_data_and_size(cap_file,&data,&size);
    Mat imgbuf(1936,1288,CV_8U,const_cast<char *>(data));
    Mat img = imdecode(imgbuf, CV_LOAD_IMAGE_COLOR);
    gp_file_free(cap_file);
    return img;
}

void LivePreview::restart() {
    timer->blockSignals(false);
    emit restart_sig();
}

void LivePreview::display_img_for_sec(cv::Mat image,int sec) {

    QTimer::singleShot(sec*1000, this, SLOT(unblock_timer()));
    timer->blockSignals(true);
    final_image_item = scene->addPixmap(QPixmap::fromImage(QImage((unsigned char *) image.data, image.cols, image.rows, QImage::Format_RGB888).rgbSwapped()).scaledToHeight(this->height()));
    scene->update();

}

void LivePreview::unblock_timer() {
    scene->removeItem(final_image_item);
    delete final_image_item;
    timer->blockSignals(false);
}
