/*
 * Prototype Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 *
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;

template<typename T>
class LifeTimeManager {
    stack<T*> store;
public:
    void push(T* p)
    {
        store.push(p);
    }
    ~LifeTimeManager()
    {
        while(!store.empty())
        {
            if(store.top() != NULL)
                delete store.top();
            store.pop();
        }
    }
};
class Prototype
{
  public:
    virtual Prototype* clone() = 0;
    virtual void call() = 0;
    virtual ~Prototype() {}
};

class ConcretePrototype : public Prototype
{
  int num;
  LifeTimeManager<Prototype> manager;

public:
  ConcretePrototype() {}
  ConcretePrototype(const ConcretePrototype& other)
  {
    this->num = other.num;
  }
  Prototype* clone()
  {
    Prototype* p = new ConcretePrototype(*this);
    manager.push(p);
    return p;
  }
  void setNum(int n)
  {
    this->num = n;
  }
  void call()
  {
    cout << "BauBau!!";
    cout << this->num << endl;
  }
  virtual ~ConcretePrototype() {}
};


int main()
{
  ConcretePrototype a;
  a.setNum(3);
  a.call();
  Prototype *b = a.clone();
  b->call();

  return EXIT_SUCCESS;
}
