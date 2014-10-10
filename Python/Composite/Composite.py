#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Composite Pattern
Author: Kei Nakata
Data: Oct.10.2014
'''
import abc
import exceptions

class Component(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def __init__(self, name):
        pass

    @abc.abstractmethod
    def add(self, child):
        pass

    @abc.abstractmethod
    def remove(self, index):
        pass

    @abc.abstractmethod
    def getChild(self, index):
        pass

    @abc.abstractmethod
    def show(self):
        pass

class Composite(Component):

    def __init__(self, name):
        self.children = []

    def add(self, child):
        self.children.append(child)

    def remove(self, index):
        del self.children[index]

    def getChild(self, index):
        return self.children[index]

    def show(self):
        for child in self.children:
            child.show()

class Leaf(Component):
    count = 0
    def __init__(self, name):
        self.name = name
        Leaf.count = Leaf.count + 1
        self.number = Leaf.count
    def add(self):
        raise exceptions.RuntimeError("can not add item to leaf")

    def remove(self):
        raise exceptions.RuntimeError("can not remove item through leaf class")

    def getChild(self):
        raise exceptions.RuntimeError("leaf does not have child")

    def show(self):
        print self.number, self.name

if __name__ == '__main__':
    container = Composite('box')
    small_container = Composite('small box')
    small_container.add(Leaf('chicken'))
    small_container.add(Leaf('beaf'))
    small_container.add(Leaf('pork'))
    container.add(Leaf('apple'))
    container.add(Leaf('orange'))
    container.add(Leaf('pear'))
    container.add(small_container)
    container.show()
    print
    container.remove(1)
    container.show()
