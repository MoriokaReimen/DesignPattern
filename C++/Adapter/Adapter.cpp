/*
 * Adapter Pattern
 * Author: Kei Nakata
 * Date: Oct.6.2014
 * Convert the interface of a class into another interface clients
 * expect. Adapter lets classes work together that couldn't otherwise
 * because of incompatible interfaces.
 */
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

class Target
{
public:
  virtual ~Target() {}
  virtual void show()
  {
    cout << "World" << endl;
  }
};

class Adaptee
{
public:
  virtual ~Adaptee() {}
  void print()
  {
    cout << "Heelo";
  }
};

class Adapter : public Target, private Adaptee
{
public:
  virtual ~Adapter() {}
  virtual void show()
  {
    Adaptee::print();
    cout << " ";
    Target::show();
  }
};

int main()
{
  Adapter a;
  a.show();

  return EXIT_SUCCESS;
}
