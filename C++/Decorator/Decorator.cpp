/*
 * Decorator Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 * Attach additional responsibilities to an object dynamically.
 * Decorators provide a flexible alternative to subclassing for
 * extending functionality.
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

class Component
{
public:
  virtual ~Component() {}
  virtual void operation() = 0;
};

class ConcreteComponet : public Component
{
public:
  void operation()
  {
    cout << "I want to eat curry rice" << endl;
  }
};

class Decorator : public Component
{
protected:
  Component* _component;
public:
  Decorator(Component* component): _component(component) {}
  virtual void operation() = 0;
};

class ConcreteDecorator : public Decorator
{
public:
  ConcreteDecorator(Component* component): Decorator(component) {}
  void operation()
  {
    _component->operation();
    cout << "and nann!!" << endl;
  }
};

int main()
{
  LifeTimeManager<Component> manager;
  ConcreteComponet* a = new ConcreteComponet;
  manager.push(a);
  ConcreteDecorator b(a);
  cout << "A:" << endl;
  a->operation();
  cout << "B:" << endl;
  b.operation();

  return EXIT_SUCCESS;
}
