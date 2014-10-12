all: Adapter.exe

Adapter.o: Adapter.cpp
	g++ -Wall -O2 -c Adapter.cpp

Adapter.exe: Adapter.o
	g++ Adapter.o -o Adapter.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Adapter.o Adapter.exe
