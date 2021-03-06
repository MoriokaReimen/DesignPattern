/*
 * AbstractFactory Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 * Provide an interface for creating families of related or dependent
 * objects without specifying their concrete classes
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;

class Product
{
public:
  virtual void call() = 0;
  virtual ~Product() {}
};

class Creator
{
public:
  virtual void factoryMethod() = 0;
  virtual Product* createA() = 0;
  virtual Product* createB() = 0;
  virtual ~Creator() {}
};

class ConcreteProductA: public Product
{
public:
  void call()
  {
    cout << "Hi!" << endl;
  }
};

class ConcreteProductB: public Product
{
public:
  void call()
  {
    cout << "Hello!" << endl;
  }
};

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
          {
            delete store.top();
          }
        store.pop();
      }
  }
};

class ConcreteCreator : public Creator
{
  int count;
  LifeTimeManager<Product> manager;
public:
  ConcreteCreator() : count(0)
  {}

  Product* createA()
  {
    this->count++;

    Product* p = new ConcreteProductA;
    manager.push(p);
    return p;
  }

  Product* createB()
  {
    this->count++;

    Product* p = new ConcreteProductB;
    manager.push(p);
    return p;
  }

  void factoryMethod()
  {
    cout << "I spawned " << this->count << " times!" << endl;
  }
};

int main()
{
  ConcreteCreator mommy;
  Product *a, *b, *c, *d;
  a = mommy.createA();
  a->call();
  b = mommy.createB();
  b->call();
  c = mommy.createA();
  c->call();
  d = mommy.createB();
  d->call();
  mommy.factoryMethod();
  return EXIT_SUCCESS;
}
