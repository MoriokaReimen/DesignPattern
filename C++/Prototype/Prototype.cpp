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

class Prototype
{
  public:
    virtual Prototype* clone() = 0;
    virtual void call() = 0;
};

class ConcretePrototype : public Prototype
{
  int num;

public:
  ConcretePrototype() {}
  ConcretePrototype(const ConcretePrototype& other)
  {
    this->num = other.num;

  }
  Prototype* clone()
  {
    return new ConcretePrototype(*this);
  }
  void call()
  {
    cout << "BauBau!!";
    cout << this->num << endl;
  }
};


int main()
{
  ConcretePrototype a;
  Prototype *b = a.clone();
  a.call();
  b->call();

  return EXIT_SUCCESS;
}
