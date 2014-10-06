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

class Singleton
{

  static bool destroyed_; // flag for destruction detection

  Singleton() {} //Prevent clients from creating a new singleton
  Singleton(const Singleton& other) {} //Prevent Clients from creating
  Singleton &operator=(const Singleton &rhs); //Prevent Clients from copy
  ~Singleton() { destroyed_ = true; } // Prevent destruction

  string msg_;
public:
  static Singleton &getInstance()
  {
    static Singleton instance;
    if(destroyed_)
      throw std::runtime_error("Singleton: Dead Reference Access");
    else
      return instance;
  }

  void setString(string msg)
  {
    this -> msg_ = msg;
  }

  void printString()
  {
    cout << this->msg_ << endl;
  }
};

bool Singleton::destroyed_ = false; //Initialize flag

int main()
{
  Singleton &i = Singleton::getInstance();
  Singleton &j = Singleton::getInstance();
  i.setString("Hello");
  i.printString();
  j.setString("Bye");
  i.printString();
  return EXIT_SUCCESS;
}
