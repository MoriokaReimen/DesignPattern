/*
 * Meyers Singleton with dead reference detect
 * Author: reimen
 * Data: Oct.6.2014
 * Ensure a class only has one instance, and provide a global point
 * of access to it.
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
  Singleton() = default; //Prevent clients from creating a new singleton
  ~Singleton()
  {
    destroyed_ = true;  // Prevent double destruction
  }

  string msg_;
public:
  Singleton(const Singleton& other) = delete;//Prevent Clients from creating
  Singleton &operator=(const Singleton &rhs) = delete; //Prevent Clients from copy

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
  auto& i = Singleton::getInstance();
  auto& j = Singleton::getInstance();
  i.setString("Hello");
  i.printString();
  j.setString("Bye");
  i.printString();
  return EXIT_SUCCESS;
}
