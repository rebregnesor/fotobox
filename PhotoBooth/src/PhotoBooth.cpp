#include <QFile>
#include <math.h>
#include "PhotoBooth.h"
#include <QShortcut>
#include <QKeySequence>
#include <QProcess>
#include <QStringList>
using namespace std;




PhotoBooth::PhotoBooth(void):gic(2,2,0.02)
{
    price = 1.0; //price per copy
    credit = 0.0; //initial credit
    
    countdown_sec = 3; //time between pictures
    n_copies = 0; //initial number of copies (determined by credit)
    n_images = 4; //n_images on one photo
    image_number = 0; //initial image number 0...n_images-1

    new QShortcut(QKeySequence("Ctrl+Q"),this,SLOT(close()));
    setGeometry(0,0,1280,1024);
    setAttribute(Qt::WA_DeleteOnClose);

    QWidget * main = new QWidget();
    QVBoxLayout * layout = new QVBoxLayout();
    main->setLayout(layout);
    setCentralWidget(main);

    info_panel = new InfoPanel(countdown_sec,0);
    info_panel->set_credit(credit);

    live_preview = new LivePreview(main);

    thumbnail_view = new ThumbnailView(main);

    layout->addLayout(info_panel);
    layout->addWidget(live_preview);
    layout->addWidget(thumbnail_view);

    connect(&countdown, SIGNAL(rem_sec_sig(int)),info_panel, SLOT(update_countdown(int))); //update GUI when Countdown object counts down
    connect(&countdown, SIGNAL(time_over_sig()),this, SLOT(take_snapshot())); //when countdown is over, take an image
    connect(live_preview, SIGNAL(restart_sig()), this, SLOT(continue_process())); //when the live preview is restarted, continue to take pictures
    connect(&arduino, SIGNAL(start()),this,SLOT(start_process())); //when the button is pressed, start the procedure
    connect(&arduino,SIGNAL(coin_inserted(double)),this,SLOT(update_credit(double))); //when a coin is inserted, update the credit

  
}

void PhotoBooth::start_process() {

    if (credit >= price) { //if credit is enough, take pictures
        disconnect(&arduino, SIGNAL(start()),this,SLOT(start_process())); //prevent two starts at once
        image_number = 0;  //reset image number
        countdown.begin(countdown_sec); //begin countdown
        n_copies = (int)floor(credit/price); //calculate number of copies
        credit -= n_copies*price; //reduce credit
        info_panel->set_credit(credit); //put new credit to the info panel
    }

}

void PhotoBooth::continue_process() {
    image_number +=1; //select next image
    if (image_number < n_images) { //if not enough images,
        countdown.begin(countdown_sec); //start countdown again.
    } else { //if all images have been taken:
        cv::Mat background = cv::imread("img/background.jpg", CV_LOAD_IMAGE_COLOR); //laod background
        final_image=gic.compose(image_list,background); //combine images
        cv::imwrite("img/final.jpg",final_image); //write image to disk
        image_list.clear();
        connect(&arduino, SIGNAL(start()),this,SLOT(start_process())); //enable start button again
        live_preview->display_img_for_sec(final_image,5); //display the final image

        //printing commands:
        QProcess printer;
        QString printer_command("/usr/bin/lpr");
        QStringList printer_args;
        printer_args.append("-P");
        printer_args.append("PhotoBooth_Printer");
        printer_args.append("-#");
        printer_args.append(QString::number(n_copies));
        //qDebug() << QString::number(n_copies);
        printer_args.append("img/final.jpg");
        printer.start(printer_command, printer_args);
        printer.waitForFinished();
    }


}

void PhotoBooth::take_snapshot() {

    cv::Mat image = live_preview->capture_image_and_save(image_number); //take picture
    image_list.push_back(image); //add picture to image list
    thumbnail_view->add_thumbnail(image_list.at(image_number), image_number); //add picture to thumbnail view
    live_preview->restart(); //restart livepreview --> continue_process() is called

}


//not needed anymore
void PhotoBooth::combine_images() {
    for (unsigned int i=0; i < image_list.size(); i++) {
        static int frame_width = 0.02*image_list.at(i).cols;
        static int width = 0.5*(image_list.at(i).cols-3.0*frame_width);
        static int height = 0.5*(image_list.at(i).rows-3.0*frame_width);
        static int positions[4][2]= { {frame_width,frame_width},
                             {2*frame_width+width,frame_width},
                             {frame_width,2*frame_width+height},
                             {2*frame_width+width,2*frame_width+height} };
        static cv::Mat background(image_list.at(i).rows, image_list.at(i).cols, CV_8UC3, cv::Scalar(255,255,255));
        cv::resize(image_list.at(i),image_list.at(i),cv::Size(width,height));
        image_list.at(i).copyTo(background(cv::Rect(positions[i][0],positions[i][1],image_list.at(i).cols,image_list.at(i).rows)));
        if (i==3) {
            imwrite("img/final.jpg", background);
            final_image=background;

        }
    }
}

void PhotoBooth::update_credit(double coin) {
    credit+=coin;
    info_panel->set_credit(credit);
}


#include <QApplication>
int main(int argc,char **argv)
{
  QApplication app(argc,argv);
  QFile stylefile("src/style.qss");
  stylefile.open(QIODevice::ReadOnly);
  app.setStyleSheet(QString(stylefile.readAll()));
  stylefile.close();
  PhotoBooth * photobooth  = new PhotoBooth();
  photobooth->show();
  return app.exec();
}

