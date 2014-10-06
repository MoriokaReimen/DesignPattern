#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Template Method Pattern
Author: reimen
Data: Oct.6.2014
'''

class takeMeal(object):
    def buy(self): pass
    def cook(self): pass
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
