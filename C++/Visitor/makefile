all: Visitor.exe

Visitor.o: Visitor.cpp
	g++ -Wall -O2 -c Visitor.cpp

Visitor.exe: Visitor.o
	g++ Visitor.o -o Visitor.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Visitor.o Visitor.exe
