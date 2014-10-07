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
  Prototype* clone()
  {
    ConcretePrototype* buff = new ConcretePrototype();
    buff->num = this->num;
    return buff;
  }
  void call() { cout << "BauBau!!" << endl; }
};


int main()
{
  ConcretePrototype a;
  ConcretePrototype *b;
  a.call();
  b->call();

  return EXIT_SUCCESS;
}
