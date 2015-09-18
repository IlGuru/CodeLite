PROJ = microcomputer.exe
CC = gcc
#OBJS = main.o window.o bus.o board.o
OBJS = main.o window.o dev_power.o dev_reset.o dev_clock.o dev_mproc.o dev_memory.o board.o op_codes.o registry.o
LDFLAGS = -lpthread -lcurses
CFLAGS = -ggdb -O2 -Wall

microcomputer : $(OBJS)
	$(CC) -o $(PROJ) $(OBJS) $(CFLAGS) $(LDFLAGS)

#main.o : main.c  bus.c  bus.h window.c window.h bit_oper.h
main.o : main.c bit_oper.h board.o window.o
	$(CC) -c main.c $(CFLAGS)
	
window.o : window.h window.c
	$(CC) -c window.h window.c $(CFLAGS)

dev_power.o : dev_power.h dev_power.c board.o
	$(CC) -c dev_power.h dev_power.c $(CFLAGS)

dev_reset.o : dev_reset.h dev_reset.c board.o
	$(CC) -c dev_reset.h dev_reset.c $(CFLAGS)

dev_clock.o : dev_clock.h dev_clock.c board.o
	$(CC) -c dev_clock.h dev_clock.c $(CFLAGS)

dev_mproc.o : dev_mproc.h dev_mproc.c board.o op_codes.o registry.o
	$(CC) -c dev_mproc.h dev_mproc.c $(CFLAGS)

dev_memory.o : dev_memory.h dev_memory.c board.o op_codes.o
	$(CC) -c dev_memory.h dev_memory.c $(CFLAGS)

board.o : board.h board.c bit_oper.h
	$(CC) -c board.h board.c $(CFLAGS)

op_codes.o : op_codes.h op_codes.c
	$(CC) -c op_codes.h op_codes.c $(CFLAGS)

registry.o : registry.h registry.c bit_oper.h
	$(CC) -c registry.h registry.c $(CFLAGS)

.PHONY: clean
clean:
	-rm -v -f $(PROJ) $(OBJS)