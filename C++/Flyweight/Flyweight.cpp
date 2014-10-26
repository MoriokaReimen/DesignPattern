/*
 * Flyweight pattern
 * Author: reimen
 * Data: Oct.14.2014
 * Use sharing to support large numbers of fine-grained objects efficiently.
 */
#include <iostream>
#include <cstdlib>
#include <map>
#include <memory>
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::shared_ptr;

class Flyweight
{
protected:
  int _key;

public:
  Flyweight(int key) : _key(key) {}
  virtual ~Flyweight() = default;
  virtual void operation() = 0;
};

class ConcreteFlyweight : public Flyweight
{
public:
  using Flyweight::Flyweight;
  void operation()
  {
    cout << _key << endl;
  }
};

class FlyweightFactory
{
protected:
  map<int, shared_ptr<Flyweight>>  _instances;
public:
  virtual ~FlyweightFactory() = default;
  shared_ptr<Flyweight> getInstance(int key)
  {
    if(_instances.find(key) == _instances.end())
    {
      shared_ptr<Flyweight> instance(new ConcreteFlyweight(key));
      _instances.insert(pair<int, shared_ptr<Flyweight>>(key, instance));
    }
    return _instances[key];
  }
};



int main()
{
  FlyweightFactory factory;
  auto a = factory.getInstance(1);
  auto b = factory.getInstance(2);
  auto c = factory.getInstance(1);
  a -> operation();
  b -> operation();
  c -> operation();
  return EXIT_SUCCESS;
}
