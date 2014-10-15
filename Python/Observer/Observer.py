#! /usr/bin/python
# -*- coding: utf-8 -*-
''' Observer Pattern
Author: Kei Nakata
Data: Oct.15.2014
'''
import abc

class Observer(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def update(self):
        pass

class Subject(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def addObserver(self, observer):
        pass

    @abc.abstractmethod
    def notifyObserver(self):
        pass

class ConcreteObserver(Observer):
    def update(self, event):
        print self.__class__.__name__, "received from", event

class ConcreteSubject(Subject):

    def __init__(self):
        self.observers = set()

    def addObserver(self, observer):
        self.observers.add(observer)

    def notifyObserver(self):
        for observer in self.observers:
            observer.update(self.__class__.__name__)

if __name__ == '__main__':
    observer = ConcreteObserver()
    subject = ConcreteSubject()
    subject.addObserver(observer)
    subject.notifyObserver()
