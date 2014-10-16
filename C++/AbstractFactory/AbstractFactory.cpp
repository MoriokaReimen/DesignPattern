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

class Product
{
public:
    virtual void call() = 0;
    virtual ~Product(){}
};

class Creator
{
public:
    virtual Product* create() = 0;
    virtual void factoryMethod() = 0;
    virtual ~Creator() {}
};

class ConcreteProduct: public Product
{
public:
  void call()
  {
    cout << "Hi!" << endl;
  }
};

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

class ConcreteCreator : public Creator
{
  int count;
  LifeTimeManager<Product> manager;
public:
    ConcreteCreator() : count(0)
    {}

    Product* create()
    {
      this->count++;

      Product* p = new ConcreteProduct;
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
  a = mommy.create();
  a->call();
  b = mommy.create();
  b->call();
  c = mommy.create();
  c->call();
  d = mommy.create();
  d->call();
  mommy.factoryMethod();
  return EXIT_SUCCESS;
}
