all: Facade.exe

Facade.o: Facade.cpp
	g++ -std=c++11 -Wall -O2 -c Facade.cpp

Facade.exe: Facade.o
	g++ Facade.o -o Facade.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Facade.o Facade.exe
