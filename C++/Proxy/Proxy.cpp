/*
 * Proxy Pattern
 * Author: Kei Nakata
 * Date: Oct.6.2014
 * Provide a surrogate or placeholder for another object to control access to it.
 */
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

class Subject
{
public:
    Subject() {};
    virtual ~Subject() {}
    virtual void Request() = 0;
};

class ConcreteSubject : public Subject
{
protected:
    friend class Proxy;
    ConcreteSubject() {}
public:
    virtual ~ConcreteSubject() {}
    virtual void Request()
    {
        cout << "Hello World!!" << endl;
    }
};

class Proxy : Subject
{
private:
    ConcreteSubject* a;
public:
    Proxy() : a() {}
    virtual ~Proxy()
    {
        if(a)
            delete a;
    }

    void Request()
    {
        if(!a) a = new ConcreteSubject;
        a->Request();
    }
};

int main()
{
    Proxy a;
    a.Request();

    return EXIT_SUCCESS;
}
