/*
 * Builder Pattern
 * Author: Kei Nakata
 * Data: Oct.6.2014
 * Separate the construction of a complex object from its
 * representation so that the same construction process can create
 * different representations.
 */
#include <iostream>
#include <cstdlib>
#include <memory>
#include <utility>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::move;

class Product
{
public:
    Product() = default;
    ~Product() = default;
  void execute()
  {
    cout << "Hi" << endl;
  }
};

class Builder
{
public:
  Builder() = default;
  virtual ~Builder() = default;
  virtual unique_ptr<Product> build() = 0;
};

class ConcreteBuilder: public Builder
{
public:
  ~ConcreteBuilder() = default;
  unique_ptr<Product> build()
  {
    unique_ptr<Product> p(new Product);
    return move(p);
  }
};

class Director
{
  ConcreteBuilder builder;
public:
  unique_ptr<Product> create()
  {
    return builder.build();
  }
};

int main()
{
  Director d;
  auto p = d.create();
  p->execute();
  return EXIT_SUCCESS;
}
