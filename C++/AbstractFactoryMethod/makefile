all: AbstractFactory.exe

AbstractFactory.o: AbstractFactory.cpp
	g++ -Wall -O2 -c AbstractFactory.cpp

AbstractFactory.exe: AbstractFactory.o
	g++ AbstractFactory.o -o AbstractFactory.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f AbstractFactory.o AbstractFactory.exe
