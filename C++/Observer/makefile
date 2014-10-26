all: Observer.exe

Observer.o: Observer.cpp
	g++ -std=c++11 -Wall -O2 -c Observer.cpp

Observer.exe: Observer.o
	g++ Observer.o -o Observer.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Observer.o Observer.exe
