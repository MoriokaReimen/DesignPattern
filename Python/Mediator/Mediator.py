#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Mediator Pattern
Author: Kei Nakata
Data: Oct.15.2014
'''
import abc

class Mediator(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def createColleague(self):
        pass

    @abc.abstractmethod
    def colleagueChanged(self):
        pass

class Colleague(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def setMediator(self, mediator):
        pass

    @abc.abstractmethod
    def controlColleague(self):
        pass

class ConcreteMediator(Mediator):
    def createColleague(self):
        self.colleague = ConcreteColleague()
        self.colleague.setMediator(self)

    def colleagueChanged(self):
        print "Hello This is Mediator"

    def zap(self):
        self.colleague.controlColleague()

class ConcreteColleague(Colleague):
    def setMediator(self, mediator):
        self.mediator = mediator

    def controlColleague(self):
        print "Hello this is colleague"
        self.mediator.colleagueChanged()

if __name__ == '__main__':
    mediator = ConcreteMediator()
    mediator.createColleague()
    mediator.zap()
