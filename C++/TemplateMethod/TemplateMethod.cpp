/*
 * Template Method Pattern
 * Author: Kei Nakata
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

class AbstractMessage
{
  virtual void printTitle() = 0;
  virtual void printBody() = 0;
  virtual void printConclusion() = 0;
public:
  void showMessage()
  {
    this->printTitle();
    this->printBody();
    this->printConclusion();
  }
};

class NeatMessage:public AbstractMessage
{
  void printTitle()
  {
    cout << "Title:Greeting" << endl;
  }
  void printBody()
  {
    cout << "This is first message." << endl;
  }
  void printConclusion()
  {
    cout << "Regards" << endl;
  }
public:
};



int main()
{
  NeatMessage a;
  a.showMessage();
  return EXIT_SUCCESS;
}
