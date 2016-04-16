#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QTimer>

class Countdown : public QTimer {
    Q_OBJECT

    signals:
        void time_over_sig();
        void rem_sec_sig(int rem_sec);
    public:
        Countdown();
        int seconds;
        int rem_sec;
        void begin (int sec);
    private slots:
        void reduce_rem_sec();


};


#endif // COUNTDOWN_H
