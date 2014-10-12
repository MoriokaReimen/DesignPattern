#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Proxy Pattern
Author: Kei Nakata
Data: Oct.6.2014
'''
import abc

class Subject(object):
    __metaclass__ = abc.ABCMeta
    @abc.abstractmethod
    def show(self):
        pass

class ConcreteSubject(Subject):
    def show(self):
        print "Hello World"

class Proxy(Subject):
    def __init__(self):
        self.concrete_subject = None

    def show(self):
        if(self.concrete_subject == None):
            self.concrete_subject = ConcreteSubject()
        self.concrete_subject.show()


if __name__ == '__main__':
    a = Proxy()
    a.show()
