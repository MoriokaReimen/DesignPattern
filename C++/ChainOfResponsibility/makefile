all: ChainOfResponsibility.exe

ChainOfResponsibility.o: ChainOfResponsibility.cpp
	g++ -Wall -O2 -c ChainOfResponsibility.cpp

ChainOfResponsibility.exe: ChainOfResponsibility.o
	g++ ChainOfResponsibility.o -o ChainOfResponsibility.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f ChainOfResponsibility.o ChainOfResponsibility.exe
