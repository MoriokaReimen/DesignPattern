/*
 * Barrier pattern
 * Intent:
 * Multiple threads to work concurrently on an algorithm in phases.
 * Each participant reaches the same barrier, it blocks until all threads
 * reaches same barrier.
 *
*/
#include <atomic>
#include <cstdlib>
#include <thread>
#include <iostream>
using std::cout;
using std::endl;

class Barrier
{
private:
    int _thread_num(0);
    std::atomic_int reached_thread(0);
    std::mutex _mutex;
public:
    Barrier(int thread_num) : _thread_num(thread_num) {}
    bool wait()
    {
        std::unique_lock<std::mutex> lock(_mutex);
        if(reached_thread.load() < _thread_num.load())
        {

            return false;
        }
        else
        {

            return true;
        }
    }
};

int main()
{
    cout << "Hello" << endl;
    return EXIT_SUCCESS;
}


