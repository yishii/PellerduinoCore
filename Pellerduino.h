/*
  Arduino-like platform for Propeller w/propgcc

  Coded by Yasuhiro ISHII 2012

  This software is distributed under Apache2.0 license.
 */

#ifndef __PELLERDUINO_H__
#define __PELLERDUINO_H__

#include <propeller.h>
#include <P8X32A_QuickStart.h>

void setup(void);
void loop(void);

void pinMode(int,int);
void digitalWrite(int,int);
int digitalRead(int);

void delay(long);

#define HIGH		1
#define	LOW		0
#define	INPUT		0
#define	OUTPUT		1

#endif /* __PELLERDUINO_H__ */
