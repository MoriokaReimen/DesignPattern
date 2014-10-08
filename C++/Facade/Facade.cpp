/*
 * Facade Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 *
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
  void printA()
  {
    cout << "A" << endl;
  }
};

class ClassB
{
public:
  void printB()
  {
    cout << "B" << endl;
  }
};

class ClassC
{
public:
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
  void execute()
  {
    this->a.printA();
    this->b.printB();
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
