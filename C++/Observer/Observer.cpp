/*
 * Observer Pattern
 * Author: reimen
 * Data: Oct.15.2014
 * Define a one-to-many dependency between objects so that when one
 * object changes state, all its dependents are notified and updated
 * automatically.
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <set>
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::type_info;

class Observer
{
public:
  virtual ~Observer() {}
  virtual void update(const string& event) = 0;
};

class Subject
{
protected:
  set<Observer*> _observers;
public:
  virtual ~Subject() {}
  virtual void addOberver(Observer* observer) = 0;
  virtual void notifyObserver() = 0;
};

class ConcreteObserver : public Observer
{
protected:
  void update(const string& event)
  {
    const type_info& id = typeid(*this);
    cout << id.name() << " updated from " << event << endl;
  }
public:
  virtual ~ConcreteObserver() {}
};

class ConcreteSubject : public Subject
{
public:
  virtual ~ConcreteSubject() {}
  virtual void addOberver(Observer* observer)
  {
    _observers.insert(observer);
  }
  virtual void notifyObserver()
  {
    for(set<Observer*>::iterator it = _observers.begin(); it != _observers.end(); ++it)
      {
        const type_info& id = typeid(*this);
        string event = id.name();
        (*it)->update(event);
      }
  }
};


int main()
{
  ConcreteSubject subject;
  ConcreteObserver observer_a, observer_b, observer_c;
  subject.addOberver(&observer_a);
  subject.addOberver(&observer_b);
  subject.addOberver(&observer_c);
  subject.notifyObserver();
  return EXIT_SUCCESS;
}
