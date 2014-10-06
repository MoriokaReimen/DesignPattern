#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Template Method Pattern
Author: reimen
Data: Oct.6.2014
'''
from abc import *

class takeMeal(object):
    __metaclass__ = ABCMeta
    @abstractmethod
    def buy(self): pass

    @abstractmethod
    def cook(self): pass

    @abstractmethod
    def eat(self): pass

    def take(self):
        self.buy()
        self.cook()
        self.eat()

class Breakfast(takeMeal):
    def buy(self):
        print "Buy Spam and Egg."

    def cook(self):
        print "Fry Spam and Egg with pan"

    def eat(self):
        print "Yummy Spam and Egg !!"

if __name__ == '__main__':
    a = Breakfast()
    a.take()
