#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
Chain Of Responsibility Pattern
Author: Kei Nakata
Data: Oct.10.2014
'''
import abc

class Handler(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def __init__(self):
        pass

    @abc.abstractmethod
    def request(self, num):
        pass

    @abc.abstractmethod
    def calc(self, num):
        pass

class ConcreteHandler5(Handler):
    def __init__(self):
        pass

    def request(self, num):
        if self.calc(num):
            print num, "is multiple of 30"

    def calc(self, num):
        if num % 5 == 0:
            print num, "is not multiple of 5"
            return True
        else:
            print num, "is not multiple of 30"
            return False

class ConcreteHandler3(Handler):
    def __init__(self):
        pass

    def request(self, num):
        if self.calc(num):
            self.nextHandler = ConcreteHandler5()
            self.nextHandler.request(num)


    def calc(self, num):
        if num % 3 == 0:
            print num, "is not multiple of 3"
            return True
        else:
            print num, "is not multiple of 3"
            return False

class ConcreteHandler2(Handler):
    def __init__(self):
        pass

    def request(self, num):
        if self.calc(num):
            self.nextHandler = ConcreteHandler3()
            self.nextHandler.request(num)

    def calc(self, num):
        if num % 2 == 0:
            print num, "is multiple of 2"
            return True
        else:
            print num, "is not multiple of 2"
            return False

if __name__ == '__main__':
    handle = ConcreteHandler2()
    handle.request(30)
    print
    handle.request(50)
    print
    handle.request(90)
    print
    handle.request(36)
