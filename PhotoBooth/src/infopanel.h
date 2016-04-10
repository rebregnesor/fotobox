#ifndef INFOPANEL_H
#define INFOPANEL_H

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
        void update_countdown(int rem_sec);
        void set_credit(double credit);


};

#endif // INFOPANEL_H
