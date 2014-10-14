#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
State Pattern
Author: Kei Nakata
Data: Oct.14.2014
'''
import abc

class State(object):
    __metaclass__ = abc.ABCMeta
    @abc.abstractmethod
    def operation(self):
        pass

class ConcreteStateA(State):
    def operation(self):
        print "Hello"

class ConcreteStateB(State):
    def operation(self):
        print "Hi"

class Context(object):
    def __init__(self, state):
        self.state = state
    def setState(self, state):
        self.state = state

    def greeting(self):
        self.state.operation()

if __name__ == '__main__':
    a = Context(ConcreteStateA())
    b = Context(ConcreteStateA())
    a.greeting()
    b.greeting()
