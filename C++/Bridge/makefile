all: Bridge.exe

Bridge.o: Bridge.cpp
	g++ -std=c++11 -Wall -O2 -c Bridge.cpp

Bridge.exe: Bridge.o
	g++ Bridge.o -o Bridge.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Bridge.o Bridge.exe
