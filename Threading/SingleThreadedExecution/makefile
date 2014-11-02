SingleThreadedExecution.out : SingleThreadedExecution.o
	g++ -lpthread -std=c++11 SingleThreadedExecution.o -o SingleThreadedExecution.out

SingleThreadedExecution.o : SingleThreadedExecution.cpp
	g++ -c -std=c++11 SingleThreadedExecution.cpp -lthread
.PHONY : all
.PHONY : clean
clean :
	rm *.out *.o
