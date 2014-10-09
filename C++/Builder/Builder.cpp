/*
 * Template Method Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 *
 */
#include <iostream>
#include <cstdlib>
#include <stack>
using std::cout;
using std::endl;
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

class Product
{
public:
  void execute()
  {
    cout << "Hi" << endl;
  }
};

class Builder
{
protected:
  LifeTimeManager<Product> manager;
public:
  virtual ~Builder(){}
  virtual Product* build() = 0;
};

class ConcreteBuilder: public Builder
{
public:
  Product* build()
  {
    Product *p = new Product;
    manager.push(p);
    return p;
  }
  ~ConcreteBuilder() {}
};

class Director
{
  ConcreteBuilder builder;
  public:
  Product* create()
  {
    return builder.build();
  }
};

int main()
{
  Director d;
  Product* p = d.create();
  p->execute();
  return EXIT_SUCCESS;
}
