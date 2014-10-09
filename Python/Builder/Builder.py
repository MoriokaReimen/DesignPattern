#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Builder Pattern
Author: reimen
Data: Oct.9.2014
'''
from abc import *

class Builder(object):
    __metaclass__ = ABCMeta
    @abstractmethod
    def build(self): pass

class Product(object):
    def execute(self):
        print "Hi"

class ConcreteBuilder(Builder):
    def build(self):
        return Product()

class Director(object):
    def __init__(self):
        self.builder = ConcreteBuilder()

    def create(self):
        return self.builder.build()

if __name__ == '__main__':
    a = Director()
    p = a.create()
    p.execute()
