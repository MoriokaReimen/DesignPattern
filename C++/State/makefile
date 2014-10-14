all: State.exe

State.o: State.cpp
	g++ -Wall -O2 -c State.cpp

State.exe: State.o
	g++ State.o -o State.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f State.o State.exe
