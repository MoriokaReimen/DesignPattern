/*!
 * Single Threaded Execution pattern
 * Intent:
 * allow only one thread to execute specific procedure.
*/
#include <cstdlib>
#include <thread>
#include <iostream>
#include <mutex>
#include <string>
#include <utility>
using std::cout;
using std::endl;
using std::string;

class SingleThreadExecution
{
private:
    int count_ = 0;
    mutable std::mutex mutex_;
public:
    SingleThreadExecution() = default;
    ~SingleThreadExecution() = default;
    void operator()(const string& message)
    {
        sharedExecution(message);
        singleExecution();
        return;
    }

    void sharedExecution(const string& message)
    {
        cout << message << endl;
        cout << "Hello" << endl;
    }

    void singleExecution()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        count_++;
        cout << this->count_ << ":" << std::this_thread::get_id() << endl;
        return;
    }
};

int main()
{
    SingleThreadExecution f;
    std::thread A(std::ref(f), "thread A");
    std::thread B(std::ref(f), "thread B");
    std::thread C(std::ref(f), "thread C");
    A.join();
    B.join();
    C.join();

    return EXIT_SUCCESS;
}


