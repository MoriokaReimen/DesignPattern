/*
 * Flyweight pattern
 * Author: reimen
 * Data: Oct.14.2014
 * Use sharing to support large numbers of fine-grained objects efficiently
 */
#include <iostream>
#include <cstdlib>
#include <map>
using std::cout;
using std::endl;
using std::map;
using std::pair;

class Flyweight
{
protected:
  int _key;

public:
  Flyweight(int key) : _key(key) {}
  virtual ~Flyweight() {}
  virtual void operation() {}
};

class ConcreteFlyweight : public Flyweight
{
public:
  ConcreteFlyweight(int key) : Flyweight(key) {}
  void operation()
  {
    cout << _key << endl;
  }
};

class FlyweightFactory
{
protected:
  map<int, Flyweight*>  _instances;
public:
  ~FlyweightFactory()
  {
    for(map<int, Flyweight*>::iterator it = _instances.begin(); it != _instances.end(); it++)
      delete it->second;
  }
  Flyweight* getInstance(int key)
  {
    if(_instances.find(key) == _instances.end())
      _instances.insert(pair<int, Flyweight*>(key, new ConcreteFlyweight(key)));
    return _instances[key];
  }
};



int main()
{
  FlyweightFactory factory;
  Flyweight *a, *b, *c;
  a = factory.getInstance(1);
  b = factory.getInstance(2);
  c = factory.getInstance(1);
  a -> operation();
  b -> operation();
  c -> operation();
  return EXIT_SUCCESS;
}
