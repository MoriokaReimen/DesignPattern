#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Factory Method Pattern
Author: Kei Nakata
Data: Oct.7.2014
'''
import abc

class Creator(object):
    __meataclass__ = abc.ABCMeta

    @abc.abstractmethod
    def create(self):
        pass

    @abc.abstractmethod
    def factoryMethod(self):
        pass

class Product(object):
    __meataclass__ = abc.ABCMeta
    @abc.abstractmethod
    def call(self):
        pass

class ConcreteCreator(Creator):
    def __init__(self):
        self.count = 0

    def create(self):
        self.count = self.count + 1
        return ConcreteProduct()
    def factoryMethod(self):
        print "I spawned", self.count, "times!"

class ConcreteProduct(object):
    def call(self):
        print "Hi!"

if __name__ == '__main__':
    A = ConcreteCreator()
    a = A.create();
    b = A.create();
    c = A.create();
    d = A.create();
    a.call()
    b.call()
    c.call()
    d.call()
    A.factoryMethod()
