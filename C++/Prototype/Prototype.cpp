/*
 * Prototype Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 * Specify the kinds of objects to create using a prototypical
 * instance, and create new objects by copying this prototype.
 */
#include <iostream>
#include <cstdlib>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Prototype
{
public:
  virtual shared_ptr<Prototype> clone() = 0;
  virtual void call() = 0;
  virtual ~Prototype() {}
};

class ConcretePrototype : public Prototype
{
  int num = 0;

public:
  ConcretePrototype() = default;
  ConcretePrototype(const ConcretePrototype& other) : num(other.num)
  {
  }
  shared_ptr<Prototype> clone()
  {
    shared_ptr<Prototype> p(new ConcretePrototype(*this));
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
  virtual ~ConcretePrototype() = default;
};


int main()
{
  ConcretePrototype a;
  a.setNum(3);
  a.call();
  auto b = a.clone();
  b->call();

  return EXIT_SUCCESS;
}
