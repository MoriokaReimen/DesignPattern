all: Singleton.exe

Singleton.o: Singleton.cpp
	g++ -std=c++11 -Wall -O2 -c Singleton.cpp

Singleton.exe: Singleton.o
	g++ Singleton.o -o Singleton.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Singleton.o Singleton.exe
