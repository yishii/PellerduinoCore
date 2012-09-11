/*
  LED Blink test for QuickStart board

  Coded by Yasuhiro ISHII
*/

#include <Pellerduino.h>

const int pinTable[8] = {
    PIN_LED0,
    PIN_LED1,
    PIN_LED2,
    PIN_LED3,
    PIN_LED4,
    PIN_LED5,
    PIN_LED6,
    PIN_LED7
};

void setup()
{
    int i;
    for(i=0;i<8;i++){
      pinMode(pinTable[i],OUTPUT);
    }
}

void loop()
{
    int i;
    static int c = 0;

    for(i=0;i<8;i++){
	if(c % 8 == i){
	    digitalWrite(pinTable[i],HIGH);
	} else {
	    digitalWrite(pinTable[i],LOW);
	}
	delay(1000);
    }
    c++;
}
