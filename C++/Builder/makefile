all: Builder.exe

Builder.o: Builder.cpp
	g++ -Wall -O2 -c Builder.cpp

Builder.exe: Builder.o
	g++ Builder.o -o Builder.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Builder.o Builder.exe
