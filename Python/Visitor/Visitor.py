#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Visitor Pattern
Author: Kei Nakata
Data: Oct.6.2014
'''
import abc

class Element(object):
    __metaclass__ = abc.ABCMeta
    @abc.abstractmethod
    def accept(self, visitor):
        pass

    @abc.abstractmethod
    def operation(self):
        pass

class Visitor(object):
    __metaclass__ = abc.ABCMeta
    @abc.abstractmethod
    def visitElement(self, element):
        pass

class ConcreteElemnt(Element):

    def accept(self, visitor):
        visitor.visitElement(self)

    def operation(self):
        print "Hello I am Element"

class ConcreteVisitor(Visitor):
    def visitElement(self, element):
        element.operation()

if __name__ == '__main__':
    visitor = ConcreteVisitor()
    element = ConcreteElemnt()
    visitor.visitElement(element)
