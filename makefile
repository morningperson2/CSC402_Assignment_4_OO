# Macros ========================================

CC=g++
CFLAGS=-c -g -Wall -Wextra -ansi -pedantic -O -Wconversion
OUTDIR=gnu/
ERASE=rm
OBJECTS=$(OUTDIR)main.o $(OUTDIR)IntWrapper.o $(OUTDIR)sort.o $(OUTDIR)StringWrapper.o
EXE=$(OUTDIR)main.exe

# Targets ========================================

$(EXE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE)

$(OUTDIR)main.o : main.cpp IntWrapper.cpp sort.cpp StringWrapper.cpp
	$(CC) $(CFLAGS) -std=c++11 main.cpp -o $(OUTDIR)main.o

$(OUTDIR)IntWrapper.o : IntWrapper.cpp IntWrapper.cpp IComparable.h
	$(CC) $(CFLAGS) -std=c++11 IntWrapper.cpp -o $(OUTDIR)IntWrapper.o

$(OUTDIR)sort.o : sort.cpp sort.h IComparable.h
	$(CC) $(CFLAGS) -std=c++11 sort.cpp -o $(OUTDIR)sort.o

$(OUTDIR)StringWrapper.o : StringWrapper.cpp StringWrapper.h IComparable.h
	$(CC) $(CFLAGS) -std=c++11 StringWrapper.cpp -o $(OUTDIR)StringWrapper.o
	
clean :
	$(ERASE) $(EXE) $(OBJECTS)

all :
	-$(MAKE) clean
	-$(MAKE)
	tablen main.cpp
	tablen Grade.cpp
	tablen Grade.h
	tablen Logger.cpp
	tablen Logger.h
	tablen Student.cpp
	tablen Student.h
	doxygen Doxyfile
	( cat Doxyfile ; echo "EXTRACT_ALL=YES" ) | doxygen -
	( cat Doxyfile ; echo "EXTRACT_ALL=NO" ) | doxygen -