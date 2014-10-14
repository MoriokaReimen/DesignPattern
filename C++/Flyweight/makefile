all: Flyweight.exe

Flyweight.o: Flyweight.cpp
	g++ -Wall -O2 -c Flyweight.cpp

Flyweight.exe: Flyweight.o
	g++ Flyweight.o -o Flyweight.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Flyweight.o Flyweight.exe
