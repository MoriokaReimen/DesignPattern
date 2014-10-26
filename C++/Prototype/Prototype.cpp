/*
 * Prototype Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 * Specify the kinds of objects to create using a prototypical
 * instance, and create new objects by copying this prototype.
 */
#include <iostream>
#include <cstdlib>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

template<typename T>
class LifeTimeManager
{
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
  ConcretePrototype(): num(0), manager() {}
  ConcretePrototype(const ConcretePrototype& other) : num(other.num), manager()
  {
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
