PROJ = microcomputer.exe
CC = gcc
#OBJS = main.o window.o bus.o board.o
OBJS = main.o window.o board.o dev_power.o dev_reset.o dev_clock.o dev_mproc.o dev_memory.o
LDFLAGS = -lpthread -lcurses
CFLAGS = -ggdb -O2 -Wall

microcomputer : $(OBJS)
	$(CC) -o $(PROJ) $(OBJS) $(CFLAGS) $(LDFLAGS)

#main.o : main.c  bus.c  bus.h window.c window.h bit_oper.h
main.o : main.c board.h window.h bit_oper.h board.c window.c
	$(CC) -c main.c $(CFLAGS)
	
window.o : window.h window.c
	$(CC) -c window.h window.c $(CFLAGS)

#bus.o : bus.c bus.h window.h bit_oper.h
#	$(CC) -c bus.c

board.o : board.h board.c bit_oper.h
	$(CC) -c board.h board.c $(CFLAGS)

dev_power.o : dev_power.h dev_power.c board.h board.c
	$(CC) -c dev_power.h dev_power.c $(CFLAGS)

dev_reset.o : dev_reset.h dev_reset.c board.h board.c
	$(CC) -c dev_reset.h dev_reset.c $(CFLAGS)

dev_clock.o : dev_clock.h dev_clock.c board.h board.c
	$(CC) -c dev_clock.h dev_clock.c $(CFLAGS)

dev_mproc.o : dev_mproc.h dev_mproc.c board.h board.c
	$(CC) -c dev_mproc.h dev_mproc.c $(CFLAGS)

dev_memory.o : dev_memory.h dev_memory.c board.h board.c
	$(CC) -c dev_memory.h dev_memory.c $(CFLAGS)

.PHONY: clean
clean:
	-rm -v -f $(PROJ) $(OBJS)