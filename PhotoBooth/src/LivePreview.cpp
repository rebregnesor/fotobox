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
    timer->start(300); //one frame per 300 milliseconds ~3.3 frames per second for higher battery life
    }

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    frame_item = scene->addPixmap(QPixmap("img/camera-photo.png").scaledToHeight(this->height())); //display some image in case camera couldn't be started
}

LivePreview::~LivePreview() {

    retval = gp_camera_exit(camera,context); //close the connection to the camera (seems to be buggy in some gphoto versions)
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
    delete frame_item; //very important: removeItem only removes the pointer. Memory leak!
    frame_item = scene->addPixmap(frame.transformed(QTransform().scale(-1.3,1.3))); //put frame on scene
    scene->update(); //force update
    gp_file_free(file);
}

Mat LivePreview::capture_image_and_save(int image_number) {
    timer->blockSignals(true); //block timer signals for some time. Timer is restarted in Photobooth.cpp to display a thumbnail before the next picture is taken.
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
    Mat img = imdecode(imgbuf, CV_LOAD_IMAGE_COLOR); //here the image is finally saved as cv::Mat
    gp_file_free(cap_file);
    return img;
}

void LivePreview::restart() {
    timer->blockSignals(false); //restarts the timer and thereby the live preview update()
    emit restart_sig();
}

void LivePreview::display_img_for_sec(cv::Mat image,int sec) {

    QTimer::singleShot(sec*1000, this, SLOT(unblock_timer())); //block timer for some time and unblock it afterwards
    timer->blockSignals(true);
    final_image_item = scene->addPixmap(QPixmap::fromImage(QImage((unsigned char *) image.data, image.cols, image.rows, QImage::Format_RGB888).rgbSwapped()).scaledToHeight(this->height()));
    scene->update();

}

void LivePreview::unblock_timer() {
    scene->removeItem(final_image_item);
    delete final_image_item; //again, very important to avoid memory leaks!
    timer->blockSignals(false);
}
