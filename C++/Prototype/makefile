all: Prototype.exe

Prototype.o: Prototype.cpp
	g++ -Wall -O2 -c Prototype.cpp

Prototype.exe: Prototype.o
	g++ Prototype.o -o Prototype.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Prototype.o Prototype.exe
