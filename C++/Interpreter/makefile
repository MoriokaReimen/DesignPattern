all: Interpreter.exe

Interpreter.o: Interpreter.cpp
	g++ -Wall -O2 -c Interpreter.cpp

Interpreter.exe: Interpreter.o
	g++ Interpreter.o -o Interpreter.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Interpreter.o Interpreter.exe
