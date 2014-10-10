all: Decorator.exe

Decorator.o: Decorator.cpp
	g++ -Wall -O2 -c Decorator.cpp

Decorator.exe: Decorator.o
	g++ Decorator.o -o Decorator.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Decorator.o Decorator.exe
