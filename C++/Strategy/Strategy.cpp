/*
 * Strategy pattern
 * Author: reimen
 * Data: Oct.13.2014
 *
 */
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

class Strategy
{
public:
    virtual ~Strategy() {}
    virtual void algorithm() = 0;
};

class ConcreteStrategy : public Strategy
{
public:
    virtual ~ConcreteStrategy() {}
    void algorithm()
    {
        cout << "Hello" << endl;
    }
};

class Context
{
protected:
    Strategy* _strategy;
public:
    Context(): _strategy(new ConcreteStrategy) {}
    virtual ~Context()
    {
        delete _strategy;
    }
    void operate()
    {
        _strategy->algorithm();
    }

};
int main()
{
    Context a;
    a.operate();
    return EXIT_SUCCESS;
}
