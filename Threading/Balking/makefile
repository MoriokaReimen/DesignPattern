Balking.out : Balking.o
	g++ -lpthread -std=c++11 Balking.o -o Balking.out

Balking.o : Balking.cpp
	g++ -c -std=c++11 Balking.cpp
.PHONY : all
.PHONY : clean
clean :
	rm *.out *.o
