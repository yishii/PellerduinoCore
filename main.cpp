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
pthread_mutex_t gpio_mutex;
void synchronized_digitalWrite(int port,int level);

void busywait(unsigned int usecs);


void* thread(void* arg)
{
    int i;

    i = (int)arg;
    pinMode(pinTable[i],OUTPUT);

    while(1){
	printf("thread [%d]\n",i);
	synchronized_digitalWrite(pinTable[i],HIGH);
	delay((i+1)*100);
	synchronized_digitalWrite(pinTable[i],LOW);
	delay((i+1)*100);
    }
}

void synchronized_digitalWrite(int port,int level)
{
    pthread_mutex_lock(&gpio_mutex);

    digitalWrite(port,level);

    pthread_mutex_unlock(&gpio_mutex);
}

void busywait(unsigned int msecs)
{
    volatile unsigned long cycles = msecs * 1000 * (_clkfreq/1000000);
    volatile unsigned long then = _CNT + cycles;
    while((long)(then - _CNT) > 0){
	//pthread_yield(); 
    }
}

void setup()
{
    int i;

    pthread_mutex_init(&gpio_mutex,NULL);

    for(i=0;i<8;i++){
	pinMode(pinTable[i],OUTPUT);
    }

    for(i=0;i<8;i++){
	pthread_create(&th[i],NULL,thread,(void*)i);
    }
}

void loop()
{
}
