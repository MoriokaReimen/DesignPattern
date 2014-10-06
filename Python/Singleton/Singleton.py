#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Singleton Pattern
Author: Kei Nakata
Data: Oct.6.2014
'''

class Singleton(object):
    def __new__(cls, *a, **k):
        if not hasattr(cls, '_inst'):
            cls._inst = super(Singleton, cls).__new__(cls, *a, **k)
        return cls._inst

    def __init__(self, *args, **kwargs):
       pass

    def setString(self, msg):
       self.msg = msg

    def printString(self):
       print self.msg

if __name__ == '__main__':
    A = Singleton()
    B = Singleton()
    A.setString("Hello")
    A.printString()
    B.setString("Bye")
    A.printString()
