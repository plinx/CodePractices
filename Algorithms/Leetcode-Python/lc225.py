__author__ = 'linx'

class Stack(object):
    def __init__(self):
        self.data = []

    def push(self, x):
        tmp = [x]
        for i in xrange(len(self.data)):
            tmp.append(self.data[i])
        self.data = tmp

    def pop(self):
        self.data.pop(0)

    def top(self):
        return self.data[0]

    def empty(self):
        return self.data == []
    pass

if __name__ == '__main__':
    s = Stack()
    s.push(1)
    s.push(2)
    print s.top()
    s.pop()
    print s.top()


    pass