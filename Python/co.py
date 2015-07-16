def coroutine(func):
    def start(*args, **kwargs):
        cr = func(*args, **kwargs)
        cr.next()
        return cr
    return start

@coroutine
def printer():
    while True:
        text = (yield)
        print text

class A(object):
    def out(self):
        strs = ["asadf", "yes", "asdf", "yes"]
        for s in strs:
            self.test().send(s)
        pass

    @coroutine
    def test(self):
        while True:
            text = (yield)
            print text
    pass

if __name__ == '__main__':
    #p = printer()
    p = A()
    p.out()
    strs = ["asadf", "yes", "asdf", "yes"]

