#ifndef INFOPANEL_H
#define INFOPANEL_H

/**

This class is responsible for displaying the credit and the current state of the countdown.

**/

#include <QLabel>
#include <QHBoxLayout>

class InfoPanel : public QHBoxLayout {

    Q_OBJECT
    public:
        InfoPanel(int countdown_sec,QWidget* parent);


    private:
        QLabel * credit_heading;
        QLabel * credit_label;
        QLabel * countdown_heading;
        QLabel * countdown_label;

    public slots:
        void update_countdown(int rem_sec); //updates the label showing the remaining seconds of the countdown
        void set_credit(double credit); //sets the current value of the credit


};

#endif // INFOPANEL_H
