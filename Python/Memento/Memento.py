#! /usr/bin/python
# -*- coding: utf-8 -*-
'''
 Memento Pattern
 Author: Kei Nakata
 Data: Oct.10.2014
'''
import copy
class Memento(object):
    def __init__(self, message):
        self.message = message

    def getState(self):
        return self.message

    def setState(self, message):
        self.message = message

class Originator(object):
    def __init__(self):
        self.message = "Hello !!"
        self.memento = Memento(self.message)

    def setMessage(self, message):
        self.message = message

    def showMessage(self):
        print self.message

    def createMemento(self):
        self.memento.setState(self.message)
        return copy.deepcopy(self.memento)

    def setMemento(self, memento):
        self.memento = memento
        self.message = self.memento.getState()

class Caretaker(object):
    def __init__(self, originator):
        self.savedata = []
        self.originator = originator

    def rollback(self):
        self.originator.setMemento(self.savedata[-1])
        if len(self.savedata) > 1:
            self.savedata.pop()

    def commit(self):
        buf = self.originator.createMemento()
        self.savedata.append(buf)

if __name__ == '__main__':
    a = Originator()
    b = Caretaker(a)
    a.setMessage("apple")
    a.showMessage()
    b.commit()
    a.setMessage("orange")
    a.showMessage()
    b.commit()
    a.setMessage("banana")
    a.showMessage()
    b.commit()
    b.rollback()
    a.showMessage()
    b.rollback()
    a.showMessage()
    b.rollback()
    a.showMessage()
