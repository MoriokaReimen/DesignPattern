#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Adapter Pattern
Author: Kei Nakata
Data: Oct.6.2014
'''

class Target(object):

    def show(self):
        print "Hello",

class Adaptee(object):

    def say(self):
        print "World"

class Adapter(Target, Adaptee):
    def show(self):
        super(Adapter, self).show()
        super(Adapter, self).say()

if __name__ == '__main__':
    a = Adapter()
    a.show()
