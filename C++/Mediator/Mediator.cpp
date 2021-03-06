/*
 * Mediator
 * Author: reimen
 * Date: Oct.15.2014
 * Define an object that encapsulates how a set of objects interact.
 * Mediator promotes loose coupling by keeping objects from
 * referring to each other explicitly, and it lets you vary their
 * interaction independently.
 */
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
class Colleague;
class Mediator;
class ConcreteMediator;

class Mediator
{
protected:
  Colleague* _colleague;
public:
  virtual ~Mediator() {}
  virtual void createColleague() = 0;
  virtual void colleagueChanged() = 0;
};

class Colleague
{
protected:
  Mediator* _mediator;
public:
  virtual ~Colleague() {}
  virtual void setMediator(Mediator* mediator) = 0;
  virtual void controlColleague() = 0;
};

class ConcreteColleague : public Colleague
{
private:

public:
  ConcreteColleague() {}
  virtual ~ConcreteColleague() {}
  void setMediator(Mediator* mediator)
  {
    _mediator = mediator;
  }
  void controlColleague()
  {
    cout << "Hello This is Colleague" << endl;
    if(_mediator != NULL)
      {
        _mediator -> colleagueChanged();
      }
    else
      {
        cout << "There is no mediator" << endl;
      }
  }
};

class ConcreteMediator : Mediator
{
public:
  virtual ~ConcreteMediator()
  {
    delete _colleague;
  }
  void createColleague()
  {
    if(_colleague == NULL)
      {
        _colleague = new ConcreteColleague;
        _colleague -> setMediator(this);
      }

  }
  void colleagueChanged()
  {
    cout << "Hello I am mediator!!" << endl;
  }
  void zap()
  {
    if(_colleague != NULL)
      {
        _colleague->controlColleague();
      }
    else
      {
        cout << "No colleague" << endl;
      }
  }
};


int main()
{
  ConcreteMediator mediator;
  mediator.createColleague();
  mediator.zap();
  return EXIT_SUCCESS;
}
