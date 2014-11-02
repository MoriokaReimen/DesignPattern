/*
 * Balking pattern
 * Intent:
 * Detect change of the state of instance and perform specific procedure.
 *
 *
*/
#include <atomic>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <condition_variable>
using std::cout;
using std::endl;

class Balking
{
    mutable bool flag = false;
    mutable std::mutex mutex_;
    mutable std::condition_variable cond_;
    int count_ = 0;
    std::thread notifer;
public:
    Balking() : notifer(&Balking::init, this) {
        notifer.detach();
    }

    void init() {
        while(true) {
            std::unique_lock<std::mutex> lock(mutex_);
            cond_.wait(lock, [&] {return flag;});
            cout << "Odd Number" << endl;
            flag = false;
        }
    }


    void increment() {
        std::chrono::milliseconds time(100);
        std::unique_lock<std::mutex> lock(mutex_);
        ++count_;
        cout << count_ << endl;
        if(count_ % 2 == 0) {
            flag = true;
            cond_.notify_one();
        }
        lock.unlock();
        std::this_thread::sleep_for(time);
        return;
    }
};
int main()
{
    Balking balk;
    balk.increment();
    balk.increment();
    balk.increment();
    balk.increment();
    balk.increment();
    balk.increment();
    balk.increment();
    balk.increment();
    return EXIT_SUCCESS;
}


