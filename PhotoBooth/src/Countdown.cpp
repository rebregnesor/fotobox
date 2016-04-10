#include "Countdown.h"

Countdown::Countdown() {

    connect(this,SIGNAL(timeout()),this,SLOT(reduce_rem_sec()));

}

void Countdown::begin(int sec) {
    seconds = sec;
    rem_sec = sec;
    emit timeout();
    start(1000);
}

void Countdown::reduce_rem_sec() {

    if (rem_sec > 0) {
        emit rem_sec_sig(rem_sec);
        rem_sec--;
    } else {
        stop();
        emit time_over_sig();
    }

}
