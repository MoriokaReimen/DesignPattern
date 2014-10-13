#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
 Bridge Pattern
 Author: Kei Nakata
 Data: Oct.10.2014
'''
import abc

class Implementation(object):
    def operation(self):
        pass

class ImplementationA(Implementation):
    def operation(self):
        print "Hello"

class ImplementationB(Implementation):
    def operation(self):
        print "Hi"

class Abstract(object):
    def __init__(self, ch):
        pass
    def operation(self):
        pass

class RedefinedAbstract(Abstract):
    def __init__(self, ch):
        if ch == 'a':
            self.imp = ImplementationA()
        else:
            self.imp = ImplementationB()

    def operation(self):
        self.imp.operation()

if __name__ == '__main__':
    a = RedefinedAbstract('a')
    b = RedefinedAbstract('b')
    a.operation()
    b.operation()
