class Singleton(object):
    def __new__(cls, *a, **k):
        if not hasattr(cls, '_inst'):
            cls._inst = super(Singleton, cls).__new__(cls, *a, **k)
            return cls._inst

    def __init__(self, *args, **kwargs):
       pass

   def 
