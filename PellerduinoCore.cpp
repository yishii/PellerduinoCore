/*
  Pellerduino Core - Arduino-like APIs

  09,Sep,2012
  Coded by Yasuhiro ISHII

  This software is distributed under Apache2.0 license.
*/

#include <stdio.h>
#include <propeller.h>
#include "Pellerduino.h"

void pinMode(int pin,int dir)
{
    if(dir == 1){
	DIRA |= 1 << pin;
    } else {
	DIRA &= ~(1 << pin);
    }
}

void digitalWrite(int pin,int data)
{
    if(data == 1){
	OUTA |= 1 << pin;
    } else {
	OUTA &= ~(1 << pin);
    }
}

int digitalRead(int pin)
{
    if(INA & (1 << pin)){
	return HIGH;
    } else {
	return LOW;
    }
}

void delay(long ms)
{
    volatile long l;
    volatile long m;

    // later,need fix it
    ms *= 10;
    for(l=0;l<ms;l++){
	for(m=0;m<180;m++);
    }
}


int main(void)
{
    setup();
    while(1){
	loop();
    }
}
