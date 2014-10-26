all: FactoryMethod.exe

FactoryMethod.o: FactoryMethod.cpp
	g++ -std=c++11 -Wall -O2 -c FactoryMethod.cpp

FactoryMethod.exe: FactoryMethod.o
	g++ FactoryMethod.o -o FactoryMethod.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f FactoryMethod.o FactoryMethod.exe
