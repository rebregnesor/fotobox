//#include <math.h>
#include "infopanel.h"


InfoPanel::InfoPanel(int countdown_sec,QWidget* parent):QHBoxLayout(parent) {

    countdown_heading = new QLabel("Countdown",parent);
    countdown_heading->setStyleSheet("font-size: 16pt");
    countdown_heading->setAlignment(Qt::AlignCenter);

    countdown_label = new QLabel(QString::number(countdown_sec),parent);
    countdown_label->setStyleSheet("font-weight: bold; font-size: 40pt");
    countdown_label->setAlignment(Qt::AlignCenter);


    credit_heading = new QLabel("EUR",parent);
    credit_heading->setStyleSheet("font-size: 16pt");
    credit_heading->setAlignment(Qt::AlignCenter);

    credit_label = new QLabel("0",parent);
    credit_label->setStyleSheet("font-weight: bold; font-size: 40pt");
    credit_label->setAlignment(Qt::AlignCenter);

    
    QVBoxLayout * countdown = new QVBoxLayout();
    QVBoxLayout * credit = new QVBoxLayout();

    countdown->addWidget(countdown_heading);
    countdown->addWidget(countdown_label);
    credit->addWidget(credit_heading);
    credit->addWidget(credit_label);

    addLayout(countdown);
    addLayout(credit);
}

void InfoPanel::update_countdown(int rem_sec) {

    countdown_label->setText(QString::number(rem_sec));

}

void InfoPanel::set_credit(double credit) {
    QString text;
    credit_label->setText(text.sprintf("%5.2f",credit));
    update();

}

