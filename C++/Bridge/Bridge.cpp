/*
 * Bridge pattern
 * Author: reimen
 * Data: Oct.13.2014
 * Decouple an abstraction from its implementation
 * so that the two can vary independently
 */
#include <iostream>
#include <cstdlib>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

class Implementor
{
public:
  Implementor() = default;
  virtual ~Implementor() = default;
  virtual void operation() = 0;
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
  shared_ptr<Implementor> _imp;
public:
  virtual void operation() = 0;
  virtual ~Abstraction() = default;
};

class RedefinedAbstraction : public Abstraction
{

public:
  RedefinedAbstraction(char ch)
  {
    if(ch == 'a')
      {
        _imp.reset(new ConcreteImplementorA);
      }
    else
      {
        _imp.reset(new ConcreteImplementorB);
  }
      }
  void operation()
  {
    _imp -> operation();
  }
  ~RedefinedAbstraction() = default;
};

int main()
{
  RedefinedAbstraction a('a'), b('b');
  a.operation();
  b.operation();

  return EXIT_SUCCESS;
}
