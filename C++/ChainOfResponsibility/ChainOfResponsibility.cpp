/*
 * Meyers Singleton with dead reference detect
 * Author: reimen
 * Data: Oct.6.2014
 *
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdexcept>
using std::cout;
using std::endl;
using std::string;
using std::runtime_error;
class Handler;
class ConcreteHandler2;
class ConcreteHandler3;
class ConcreteHandler5;
class Facade;

class Handler
{
public:
  virtual ~Handler() {}
  virtual void request(int num) = 0;
};

class ConcreteHandler5: public Handler
{
public:
  ~ConcreteHandler5() {}
  void request(int num)
  {
    if(num % 5 == 0)
    {
      cout << num << " is multiple of 5." << endl;
      cout << num << " is multiple of 30." << endl;
    }
    else
      cout << num << " is not multiple of 5." << endl;
  }
};

class ConcreteHandler3: public Handler
{
public:
  ~ConcreteHandler3() {}
  void request(int num)
  {
    if(num % 3 == 0)
    {
      cout << num << " is multiple of 3." << endl;
      Handler* next = new ConcreteHandler5();
      next->request(num);
      delete next;
    }
    else
      cout << num << " is not multiple of 3." << endl;
  }
};

class ConcreteHandler2: public Handler
{
public:
  ~ConcreteHandler2() {}
  void request(int num)
  {
    if(num % 2 == 0)
    {
      cout << num << " is multiple of 2." << endl;
      Handler* next = new ConcreteHandler3();
      next->request(num);
      delete next;
    }
    else
      cout << num << " is not multiple of 2." << endl;
  }
};

class Facade
{
public:
  void calc(int num)
  {
    Handler* next;
    next = new ConcreteHandler2;
    next->request(num);
    delete next;
  }
};
int main()
{
  Facade facade;
  facade.calc(30);
  facade.calc(36);
  facade.calc(2);

  return EXIT_SUCCESS;
}
