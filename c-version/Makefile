# Makefile for test-stats, a program to validate
#   functions to calculate basic statistics of
#   a stream of float/double values iteratively
#
#2022.05.16	Inital version
#Author: HDTodd@gmail.com, Williston VT
#

CC = gcc
PROJ = test-stats
LDFLAGS = -lm

OBJS   = test-stats.o stats.o

all:	${PROJ}

.SUFFIXES: .c

.c.o:	
	$(CC) $(CFLAGS) -c $<

${PROJ}: ${OBJS}
	$(CC) -o $@ ${OBJS} ${LDFLAGS}

clean:
	/bin/rm -f *~ *.o ${PROJ}


