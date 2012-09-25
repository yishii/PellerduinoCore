/*
  LED Blink test for QuickStart board

  Coded by Yasuhiro ISHII
*/

#include <Pellerduino.h>

extern "C" {
#include <pthread.h>
}

#include <stdio.h>

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

pthread_t th[8];

void* thread(void* arg)
{
    //

}

void busywait(unsigned int usecs)
{
  unsigned long cycles = usecs * (_clkfreq/1000000);
  unsigned long then = _CNT + cycles;
  while((long)(then - _CNT) > 0);
  //pthread_yield(); 
}

void setup()
{
    printf("in setup\n");

    int i;
    for(i=0;i<8;i++){
      pinMode(pinTable[i],OUTPUT);
    }

    for(i=0;i<4;i++){
	pthread_create(&th[i],NULL,thread,(void*)i);
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
