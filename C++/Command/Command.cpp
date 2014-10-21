/*
 * Command Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 * Encapsulate a request as an object, thereby letting you parameterize
 * clients with different requests, queue or log requests, and support
 * undoable operations.
 */
#include <iostream>
#include <cstdlib>
#include <list>
using std::cout;
using std::endl;
using std::list;

class Command
{
public:
  Command() {}
  virtual ~Command() {}
  virtual void execute() = 0;
};

class ConcreteCommand : public Command
{
public:
  void execute()
  {
    cout << "Hello" << endl;
  }
};

class Invoker
{
  list<Command*> _command_list;
public:
  void execute()
  {
    while(!_command_list.empty())
      {
        _command_list.front()->execute();
        _command_list.pop_front();
      }
  }
  void store(Command* cmd)
  {
    _command_list.push_back(cmd);
  }
};

int main()
{
  Invoker a;
  ConcreteCommand b, c, d;
  a.store(&b);
  a.store(&c);
  a.store(&d);
  a.execute();
  return EXIT_SUCCESS;
}
