#! /bin/python
# -*- coding: utf-8 -*-
import abc
import copy

class Prototype(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def clone(self):
        pass

class ConcretePrototype(Prototype):
    def clone(self):
        clone = copy.deepcopy(self)
        return clone

    def setNum(self, n):
        self.num = n

    def printNum(self):
        print self.num

if __name__ == '__main__':
    a = ConcretePrototype()
    a.setNum(3)
    a.printNum()
    b = a.clone()
    b.printNum()
