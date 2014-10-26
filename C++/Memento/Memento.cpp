/*
 * Memento pattern
 * Author: reimen
 * Data: Oct.6.2014
 * Without violating encapsulation, capture and externalize an object's internal
 * state so that the object can be restored to this state later
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;

class Memento
{
private:
  string _message = "Hello";
private:
  friend class Originator;
  Memento() = default;
  void setState(const string& message)
  {
    _message = message;
  }
  string getState() const
  {
    return _message;
  }
public:
  virtual ~Memento() = default;
};

class Originator
{
private:
  Memento _memento;
  string _message;
private:
  friend class Caretaker;
  Memento createMemento()
  {
    _memento.setState(_message);
    return _memento;
  }

  void setMemento(const Memento& memento)
  {
    _memento = memento;
    _message = _memento.getState();
  }
public:
  Originator() = default;
  virtual ~Originator() = default;
  void setMessage(const string& message)
  {
    _message = message;
  }

  void printMessage()
  {
    cout << _message << endl;
  }
};

class Caretaker
{
  stack<Memento> _savedata;
  Originator* _originator;
public:
  Caretaker(Originator* originator): _originator(originator) {}
  virtual ~Caretaker() = default;
  void commit()
  {
    Memento buff = (_originator -> createMemento());
    _savedata.push(buff);
  }
  void rollback()
  {
    Memento buff = _savedata.top();
    if(_savedata.size() > 1) _savedata.pop();
    _originator -> setMemento(buff);
  }
};

int main()
{
  Originator a;
  Caretaker b(&a);
  a.setMessage("apple");
  a.printMessage();
  b.commit();
  a.setMessage("banana");
  a.printMessage();
  b.commit();
  a.setMessage("orange");
  a.printMessage();
  b.commit();
  cout << "\n";
  b.rollback();
  a.printMessage();
  b.rollback();
  a.printMessage();
  b.rollback();
  a.printMessage();
  return EXIT_SUCCESS;
}
