#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Decorator Pattern
Author: Kei Nakata
Data: Oct.10.2014
'''
import abc
import exceptions

class Component(object):

    def operation(self):
        print "I want to eat curry"

class ConcreteComponent(Component):

    def operation(self):
        print "I want to eat curry rice"

class Decorator(object):
    __metaclass__ = abc.ABCMeta
    def __init__(self):
        self.component = Component()

    @abc.abstractmethod
    def operation(self):
        pass

class ConcreteDecorator(Decorator):

    def operation(self):
        self.component.operation()
        print "and nann!!"

if __name__ == '__main__':
    a = ConcreteComponent()
    b = ConcreteDecorator()
    print "A:"
    a.operation()
    print "B:"
    b.operation()
