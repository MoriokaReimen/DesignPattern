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
    virtual ~Prototype() {}
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

  delete b;
  return EXIT_SUCCESS;
}
