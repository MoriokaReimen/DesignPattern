/*
 * State pattern
 * Author: reimen
 * Data: Oct.14.2014
 *
 */
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

class State
{
public:
  virtual ~State(){}
  virtual void operation() = 0;
};

class ConcreteStateA : public State
{
public:
  ~ConcreteStateA() {}
  void operation()
  {
    cout << "Hello" << endl;
  }
};

class ConcreteStateB : public State
{
public:
  ~ConcreteStateB() {}
  void operation()
  {
    cout << "Hi" << endl;
  }
};

class Context
{
protected:
  State* _state;
public:
  Context() : _state(new ConcreteStateA) {}
  ~Context()
  {
    if(_state != NULL)
      delete _state;
  }

  void setState(State* state)
  {
    if(_state != NULL)
      delete _state;
    _state = state;
  }
  void greeting()
  {
    _state -> operation();
  }
};

int main()
{
  Context a, b;
  a.greeting();
  b.setState(new ConcreteStateB);
  b.greeting();

  return EXIT_SUCCESS;
}
