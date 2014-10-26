all: Proxy.exe

Proxy.o: Proxy.cpp
	g++ -std=c++11 -Wall -O2 -c Proxy.cpp

Proxy.exe: Proxy.o
	g++ Proxy.o -o Proxy.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Proxy.o Proxy.exe
