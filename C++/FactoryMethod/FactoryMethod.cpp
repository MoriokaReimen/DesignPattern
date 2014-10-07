/*
 * Prototype Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 *
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;

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

class ConcreteCreator : public Creator
{
  int count;
public:
    ConcreteCreator() : count(0)
    {}

    Product* create()
    {
      this->count++;
      return new ConcreteProduct;
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
  delete a;
  delete b;
  delete c;
  delete d;
  return EXIT_SUCCESS;
}
