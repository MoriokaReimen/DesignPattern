#include <iostream>
#include <cstring>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;

class Singleton
{
  string msg_;

  Singleton(); //Prevent clients from creating a new singleton
  Singleton(const Singleton& rhs); //Prevent Clients from creating
  Singleton& operator=(const Singleton& rhs); //Prevent Clients from copy

public:
  static Singleton& getInstance(void)
  {
    static Singleton obj;
    return &obj;
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

int main()
{
  Singleton i = Singleton::getInstance();
  i.setString("Hello");
  i.printString();
  return EXIT_SUCCESS;
}
