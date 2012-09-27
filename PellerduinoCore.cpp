/*
  Pellerduino Core - Arduino-like APIs

  27,Sep,2012
  Coded by Yasuhiro ISHII
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

void delay(unsigned long ms)
{
    unsigned long cycles = ms * 1000 * (_clkfreq/1000000);
    unsigned long then = _CNT + cycles;
    while((long)(then - _CNT) > 0);
}

void delayMicroseconds(unsigned long us)
{
    unsigned long cycles = us * (_clkfreq/1000000);
    unsigned long then = _CNT + cycles;
    while((long)(then - _CNT) > 0);
}

int main(void)
{
    setup();
    while(true){
	loop();
    }
}
