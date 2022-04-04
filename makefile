# Macros ========================================

CC=g++
CFLAGS=-c -g -Wall -Wextra -ansi -pedantic -O2 -Wconversion
OUTDIR=gnu/
ERASE=rm
OBJECTS=$(OUTDIR)OOP.o $(OUTDIR)Template.o
EXE=$(OUTDIR)OOP.exe
EXE2=$(OUTDIR)Template.exe

# Targets ========================================

$(EXE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE)

$(EXE2): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE2)

$(OUTDIR)OOP.o : OOP.cpp
	$(CC) $(CFLAGS) -std=c++11 OOP.cpp -o $(OUTDIR)OOP.o

$(OUTDIR)Template.o : Template.cpp
	$(CC) $(CFLAGS) -std=c++11 Template.cpp -o $(OUTDIR)Template.o
	
clean :
	$(ERASE) $(EXE) $(OBJECTS)

all :
	-$(MAKE) clean
	-$(MAKE) $(EXE)
	-$(MAKE) $(EXE2)
	#tablen OOP.cpp
	#tablen Template.cpp
	doxygen Doxyfile
	( cat Doxyfile ; echo "EXTRACT_ALL=YES" ) | doxygen -
	( cat Doxyfile ; echo "EXTRACT_ALL=NO" ) | doxygen -