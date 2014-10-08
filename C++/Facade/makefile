all: Facade.exe

Facade.o: Facade.cpp
	g++ -Wall -O2 -c Facade.cpp

Facade.exe: Facade.o
	g++ Facade.o -o Facade.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Facade.o Facade.exe
