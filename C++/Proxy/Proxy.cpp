/*
 * Proxy Pattern
 * Author: Kei Nakata
 * Date: Oct.6.2014
 * Provide a surrogate or placeholder for another object to control
 * access to it.
 */
#include <iostream>
#include <cstdlib>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class Subject
{
public:
  Subject() = default;
  virtual ~Subject() = default;
  virtual void Request() = 0;
};

class ConcreteSubject : public Subject
{
protected:
  friend class Proxy;
  ConcreteSubject() = default;
public:
  virtual ~ConcreteSubject() = default;
  virtual void Request()
  {
    cout << "Hello World!!" << endl;
  }
};

class Proxy : Subject
{
private:
  unique_ptr<ConcreteSubject> a;
public:
  Proxy() = default;
  virtual ~Proxy() = default;

  void Request()
  {
    if(!a) a.reset(new ConcreteSubject);
    a->Request();
  }
};

int main()
{
  Proxy a;
  a.Request();

  return EXIT_SUCCESS;
}
