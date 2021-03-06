## Makefile
# 
# If this file has the default name of "Makefile", you 
# can use the Unix/Linux make command as follows:
#
# make - Build executable.
#
# make clean - Delete the .o files.
#
# make real_clean - Delete the .o files and executables.

# Note how variables are used for ease of modification.

CC = gcc
LD = gcc

# specify compile and link options
CFLAGS = -c -std=c99 -pedantic-errors -Wmissing-prototypes -Wall
LFLAGS = -Wall
DEBUGFLAGS = -g3 -DDEBUG

OBJS1 = day1.o utils.o
OBJS2 = day2.o utils.o
OBJS3 = day3.o utils.o
DAY1 = 01/day1.exe
DAY2 = 02/day2.exe
DAY3 = 03/day3.exe
#ex. DEBUG = $(DAY1)_debug

# following asks for executables to be built
default:  $(DAY3)
1: $(DAY1)
2: $(DAY2)
3: $(DAY3)
#debug: $(DEBUG)

# executables
$(DAY1): $(OBJS1) 
	$(LD) $(LFLAGS) $(OBJS1) -o $(DAY1)

$(DAY2): $(OBJS2)
	$(LD) $(LFLAGS) $(OBJS2) -o $(DAY2)

$(DAY3): $(OBJS3)
	$(LD) $(LFLAGS) $(DEBUGFLAGS) $(OBJS3) -o $(DAY3)
	
#ex. $(DEBUG): $(OBJS)
#	$(LD) $(LFLAGS) $(DEBUGFLAGS) $(OBJS) -o $(DEBUG)

#object files
day1.o: 01/day1.c util/utils.h
	$(CC) $(CFLAGS) 01/day1.c

day2.o: 02/day2.c util/utils.h
	$(CC) $(CFLAGS) 02/day2.c

day3.o: 03/day3.c util/utils.h
	$(CC) $(CFLAGS) 03/day3.c

utils.o: util/utils.c util/utils.h 
	$(CC) $(CFLAGS) util/utils.c


# other shell commands can appear as "things to do" - not just compilations, etc.
clean:
	rm -f *.o

real_clean:
	rm -f *.o
	rm -f *.exe
