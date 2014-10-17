/*
 * Visitor Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 * Represent an operation to be performed on the elements
 * of an objectstructure. Visitor lets you define a new operation without
 * changing the class of the elements on which it operates.
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
using std::cout;
using std::endl;
using std::string;
class Element;
class ConcreteElement;
class Visitor;
class ConcreteVisitor;

class Element
{
public:
  virtual ~Element() {}
  virtual void accept(Visitor* visitor) = 0;
  virtual string operation() = 0;
};

class Visitor
{
public:
  virtual ~Visitor() {}
  virtual void visitElement(Element* element) = 0;
};

class ConcreteVisitor : public Visitor
{
public:
  virtual ~ConcreteVisitor() {}
  void visitElement(Element* element)
  {
    cout << element->operation() << endl;
  }
};

class ConcreteElement : public Element
{
public:
  ~ConcreteElement() {}
  void accept(Visitor* visitor)
  {
    visitor -> visitElement(this);
  }

  string operation()
  {
    return "Hello I am Element";
  }
};


int main()
{
  ConcreteVisitor visitor;
  ConcreteElement element;
  element.accept(&visitor);

  return EXIT_SUCCESS;
}
