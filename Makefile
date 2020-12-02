## Makefile for project 1
# The comments below introduce how a makefile works.
#
# This makefile assumes that all of the source files and compiler output are
# in the same directory as this makefile.
# 
# If this file has the default name of "Makefile", you 
# can use the Unix/Linux make command as follows:
#
# make - Build executable.
#
# make clean - Delete the .o files.
#
# make real_clean - Delete the .o files and the two executables.

# Note how variables are used for ease of modification.

CC = gcc
LD = gcc

# specify compile and link options
CFLAGS = -c -std=c99 -pedantic-errors -Wmissing-prototypes -Wall
LFLAGS = -Wall
DEBUGFLAGS = -g3 -DDEBUG

OBJS = main.o
EX = 01/day1.exe
DEBUG = $(EX)_debug

# following asks for both executables to be built
default:  $(EX)
debug: $(DEBUG)

# to build this executable, check to see if any of the listed object files
# need to be rebuilt and do so, then link to create the executable
$(EX): $(OBJS)
	$(LD) $(LFLAGS) $(OBJS) -o $(EX)
	
$(DEBUG): $(OBJS)
	$(LD) $(LFLAGS) $(DEBUGFLAGS) $(OBJS) -o $(DEBUG)

# to build this object module, check the timestamps of what it depends on, and
# if any are more recent than an existing p1_main.o, then recompile p1_main.c
main.o: 01/main.c
	$(CC) $(CFLAGS) 01/main.c

# other shell commands can appear as "things to do" - not just compilations, etc.
clean:
	rm -f *.o

real_clean:
	rm -f *.o
	rm -f $(EX)
