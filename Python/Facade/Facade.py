class Facade(object):
    def __init__(self):
        self.a = ClassA()
        self.b = ClassB()
        self.c = ClassC()
    def execute(self):
        self.a.printA()
        self.b.printB()
        self.c.printC()


class ClassA(object):
    def __init__(self):
        self.b = ClassB()
        self.c = ClassC()

    def printA(self):
        self.b.printB()
        self.c.printC()

class ClassB(object):
    def printB(self):
        print "B"

class ClassC(object):
    def printC(self):
        print "C"

if __name__ == '__main__':
    facade = Facade()
    facade.execute()
