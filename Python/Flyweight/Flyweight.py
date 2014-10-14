#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Flyweight Pattern
Author: Kei Nakata
Data: Oct.14.2014
'''

class FlyweightFactory(object):
    def __init__(self):
        self.instances = dict()

    def getInstance(self, a, b):
        if (a, b) not in self.instances:
            self.instances[(a,b)] = Flyweight(a, b)
        return self.instances[(a, b)]

class Flyweight(object):
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def method(self):
        print self.a, self.b

if __name__ == '__main__':
    factory = FlyweightFactory()
    a = factory.getInstance(1, 2)
    b = factory.getInstance(3, 2)
    c = factory.getInstance(1, 2)
    a.method()
    b.method()
    c.method()
    print id(a)
    print id(b)
    print id(c)

