/**

The Countdown class is responsible for generating a Countdown timer
that emits one signal after every second in order to keep the GUI
up-to-date and one final signal when zero seconds are remaining.
The latter triggers the capture of a picture.

**/

#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QTimer>

class Countdown : public QTimer {
    Q_OBJECT

    signals:
        void time_over_sig(); //final signal when countdown time is over
        void rem_sec_sig(int rem_sec); //signal to tell the other GUI components how many seconds are remaining
    public:
        Countdown(); //constructor
        int seconds; //countdown duration
        int rem_sec; //remaining seconds
        void begin (int sec); //start a countdown
    private slots:
        void reduce_rem_sec(); //count one second down


};


#endif // COUNTDOWN_H
