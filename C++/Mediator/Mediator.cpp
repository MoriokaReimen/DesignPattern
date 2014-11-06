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
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;
class Colleague;
class Mediator;
class ConcreteMediator;

class Mediator
{
protected:
  shared_ptr<Colleague> colleague_;
public:
  virtual ~Mediator() = default;
  virtual void createColleague() = 0;
  virtual void colleagueChanged() = 0;
};

class Colleague
{
protected:
  Mediator* mediator_;
public:
  virtual ~Colleague() = default;
  virtual void setMediator(Mediator* mediator) = 0;
  virtual void controlColleague() = 0;
};

class ConcreteColleague : public Colleague
{
private:

public:
  ConcreteColleague() = default;
  virtual ~ConcreteColleague() override = default;
  void setMediator(Mediator* mediator) override
  {
    mediator_ = mediator;
  }
  void controlColleague() override
  {
    cout << "Hello This is Colleague" << endl;
    if(mediator_ != nullptr)
      {
        mediator_ -> colleagueChanged();
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
  virtual ~ConcreteMediator() override = default;
  void createColleague() override
  {
    if(colleague_ == nullptr)
      {
        colleague_.reset(new ConcreteColleague);
        colleague_ -> setMediator(this);
      }

  }
  void colleagueChanged() override
  {
    cout << "Hello I am mediator!!" << endl;
  }
  void zap()
  {
    if(colleague_ != nullptr)
      {
        colleague_ -> controlColleague();
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
