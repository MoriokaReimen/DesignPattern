all: Decorator.exe

Decorator.o: Decorator.cpp
	g++ -std=c++11 -Wall -O2 -c Decorator.cpp

Decorator.exe: Decorator.o
	g++ -std=c++11 Decorator.o -o Decorator.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Decorator.o Decorator.exe
