# Propeller build Makefile
#
# Yasuhiro ISHII 2012
# ishii.yasuhiro@gmail.com

CROSS_ENV	=  propeller-elf-
CC		=  $(CROSS_ENV)gcc
CPP		=  $(CROSS_ENV)g++
CFLAGS		=  -Os -I. -fno-exceptions -mlmm -lpthread -pthread
CPPFLAGS	=  -Os -I. -fno-exceptions -mlmm -lpthread -pthread
LCFLAGS		=  -pthread -lpthread
TARGET		=  target.elf
OBJS		=  main.o
DOWNLOADER	=  propeller-load
DLOPT		=  -r


COMMONOBJS	=  PellerduinoCore.o

OBJS		+= $(COMMONOBJS)
#CFLAGS		+= -Wall -mcog

.c.o:
	$(CC) $(CFLAGS) -c $<
.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LCFLAGS)


.PHONY: clean
clean:
	-rm $(OBJS) $(TARGET) $(COMMONOBJS)

.PHONY: purge
purge:
	-rm *~

.PHONY: download
download:
	$(DOWNLOADER) $(DLOPT) $(TARGET)
