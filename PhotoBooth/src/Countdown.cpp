/**

The Countdown class is responsible for generating a Countdown timer
that emits one signal after every second in order to keep the GUI
up-to-date and one final signal when zero seconds are remaining.
The latter triggers the capture of a picture.

**/
#include "Countdown.h"


Countdown::Countdown() {
    //use the timeout() signal of the QTimer class to count one second down.
    connect(this,SIGNAL(timeout()),this,SLOT(reduce_rem_sec()));

}

//start a countdown of sec seconds
void Countdown::begin(int sec) {
    seconds = sec; //set the duration of the Countdown
    rem_sec = sec; //initialize the value of remaining seconds
    emit timeout(); //emit timeout() signal to start the Countdown right away
    start(1000);    //emits a timeout() signal after every second which then triggers reduce_rem_sec()
}

//reduce remaining seconds rem_sec by one
void Countdown::reduce_rem_sec() {

    if (rem_sec > 0) { //if more than zero seconds are remaining,
        emit rem_sec_sig(rem_sec); //tell the value to the GUI and
        rem_sec--;                 //reduce rem_sec by one
    } else {    //if no more seconds are remaining,
        stop(); //stop the QTimer --> no more timeout() signals are emitted
        emit time_over_sig(); //emit final signal
    }

}
