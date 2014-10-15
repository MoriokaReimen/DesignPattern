all: Mediator.exe

Mediator.o: Mediator.cpp
	g++ -Wall -O2 -c Mediator.cpp

Mediator.exe: Mediator.o
	g++ Mediator.o -o Mediator.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Mediator.o Mediator.exe
