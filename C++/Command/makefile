all: Command.exe

Command.o: Command.cpp
	g++ -Wall -O2 -c Command.cpp

Command.exe: Command.o
	g++ Command.o -o Command.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Command.o Command.exe
