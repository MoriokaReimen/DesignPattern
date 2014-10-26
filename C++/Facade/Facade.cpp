/*
 * Facade Pattern
 * Author: Kei Nakata
 * Date: Oct.6.2014
 * Provide a unified interface to a set of interfaces in a subsystem.
 * Facade defines aa higher-level interface that makes the subsystem
 * easier to  use.
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
using std::cout;
using std::endl;

class ClassA
{
public:
  ClassA() = default;
  virtual ~ClassA() = default;
  void printA()
  {
    cout << "A" << endl;
  }
};

class ClassB
{
public:
  ClassB() = default;
  virtual ~ClassB() = default;
  void printB()
  {
    cout << "B" << endl;
  }
};

class ClassC
{
public:
  ClassC() = default;
  virtual ~ClassC() = default;
  void printC()
  {
    cout << "C" << endl;
  }
};

class Facade
{
public:
  ClassA a;
  ClassB b;
  ClassC c;
  Facade() = default;
  virtual ~Facade() = default;
  void execute()
  {
    this->b.printB();
    this->a.printA();
    this->c.printC();
  }
};

int main()
{
  Facade facade;
  facade.execute();
  facade.a.printA();
  facade.b.printB();
  facade.c.printC();

  return EXIT_SUCCESS;
}
