#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Command Pattern
Author: Kei Nakata
Data: Oct.8.2014
'''
import abc
class Command(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def execute(self):
        pass

class ConcreteCommand(Command):
    def execute(self):
        print "Hi"

class Invoker(object):
    def __init__(self, command):
        self.command = command

    def execute(self):
        self.command.execute()
if __name__ == '__main__':
    A = ConcreteCommand()
    B = Invoker(A)
    B.execute()
