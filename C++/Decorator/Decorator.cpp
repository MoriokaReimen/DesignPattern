/*
 * Decorator Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 * Attach additional responsibilities to an object dynamically.
 * Decorators provide a flexible alternative to subclassing for
 * extending functionality.
 */
#include <iostream>
#include <memory>
#include <cstring>
#include <cstdlib>
#include <stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::shared_ptr;
using std::move;

class Component
{
public:
    virtual ~Component() = default;
    virtual void operation() = 0;
};

class ConcreteComponet : public Component
{
public:
    void operation() override {
        cout << "I want to eat curry rice" << endl;
    }
};

class Decorator : public Component
{
protected:
    shared_ptr<Component> component_;
public:
    Decorator(shared_ptr<Component>& component): component_ {component} {}
    virtual ~Decorator() override = default;
    virtual void operation() = 0;
};

class ConcreteDecorator : public Decorator
{
public:
    using Decorator::Decorator;
    virtual ~ConcreteDecorator() override = default;
    void operation() override {
        component_ -> operation();
        cout << "and nann!!" << endl;
    }
};

int main()
{
    shared_ptr<Component> a {new ConcreteComponet};
    ConcreteDecorator b {a};
    cout << "A:" << endl;
    a->operation();
    cout << "B:" << endl;
    b.operation();

    return EXIT_SUCCESS;
}
