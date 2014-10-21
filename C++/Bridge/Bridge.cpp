/*
 * Bridge pattern
 * Author: reimen
 * Data: Oct.13.2014
 * Decouple an abstraction from its implementation
 * so that the two can vary independently
 */
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;

class Implementor
{
public:
  virtual ~Implementor() {}
  virtual void operation() {}
};

class ConcreteImplementorA : public Implementor
{

public:
  void operation()
  {
    cout << "Hello" << endl;
  }
};

class ConcreteImplementorB : public Implementor
{

public:
  void operation()
  {
    cout << "Hi" << endl;
  }
};

class Abstraction
{
protected:
  Implementor *_imp;
public:
  virtual void operation() = 0;
  virtual ~Abstraction() {}
};

class RedefinedAbstraction : public Abstraction
{

public:
  RedefinedAbstraction(char ch)
  {
    if(ch == 'a')
      _imp = new ConcreteImplementorA;
    else
      {
        _imp = new ConcreteImplementorB;
      }
  }
  void operation()
  {
    _imp -> operation();
  }
  ~RedefinedAbstraction()
  {
    delete _imp;
  }
};

int main()
{
  RedefinedAbstraction a('a'), b('b');
  a.operation();
  b.operation();

  return EXIT_SUCCESS;
}
