all: Composite.exe

Composite.o: Composite.cpp
	g++ -std=c++11 -Wall -O2 -c Composite.cpp

Composite.exe: Composite.o
	g++ Composite.o -o Composite.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Composite.o Composite.exe
