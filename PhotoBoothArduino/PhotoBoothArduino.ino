
#include "TimerOne.h"

const int start_btn =  2;
const int coin_acceptor = 3;
  
unsigned long last_time_clicked = 0;
unsigned long timer_time = 0;
unsigned int coin_pulse_value = 50; //50ct per pulse
unsigned int money;
unsigned long last_coin_pulse = 0;
long timer_interval_ms = 200;   


void setup() {
  pinMode(start_btn, INPUT_PULLUP);
  attachInterrupt(0,start_btn_clicked, FALLING);
  pinMode(coin_acceptor, INPUT_PULLUP);
  attachInterrupt(1,coin_pulse,FALLING);
  Serial.begin(9600); 
 
  Timer1.initialize(timer_interval_ms*1000);
  Timer1.attachInterrupt(send_money);
}

void loop()
{
}

void start_btn_clicked() {
   if (millis()-last_time_clicked>500) {
     Serial.println("s"); 
   }
   last_time_clicked=millis();
}

void coin_pulse() {
   timer_time = millis();
   money+=coin_pulse_value;  
}

void send_money() {
    if (money!=0 && millis()-timer_time > timer_interval_ms) {
      Serial.println(money);
      money=0; 
    }
}

