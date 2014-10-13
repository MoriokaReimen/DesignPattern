#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Strategy Pattern
Author: Kei Nakata
Data: Oct.14.2014
'''
import abc

class Strategy(object):
    __metaclass__ = abc.ABCMeta
    @abc.abstractmethod
    def operation(self):
        pass

class ConcreteStrategyA(Strategy):
    def operation(self):
        print "Hello"

class ConcreteStrategyB(Strategy):
    def operation(self):
        print "Hi"

class Context(object):
    def __init__(self, strategy):
        self.strategy = strategy
    def greeting(self):
        self.strategy.operation()

if __name__ == '__main__':
    a = Context(ConcreteStrategyA())
    b = Context(ConcreteStrategyB())
    a.greeting()
    b.greeting()
