all: Strategy.exe

Strategy.o: Strategy.cpp
	g++ -Wall -O2 -c Strategy.cpp

Strategy.exe: Strategy.o
	g++ Strategy.o -o Strategy.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Strategy.o Strategy.exe
