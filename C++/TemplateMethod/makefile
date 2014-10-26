all: TemplateMethod.exe

TemplateMethod.o: TemplateMethod.cpp
	g++ -std=c++11 -Wall -O2 -c TemplateMethod.cpp

TemplateMethod.exe: TemplateMethod.o
	g++ TemplateMethod.o -o TemplateMethod.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f TemplateMethod.o TemplateMethod.exe
