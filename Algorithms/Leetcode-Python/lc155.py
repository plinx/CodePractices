__author__ = 'linx'

class MinStack:
    # initialize your data structure here.
    def __init__(self):
        self.data = []
        self.mins = []

    # @param x, an integer
    # @return an integer
    def push(self, x):
        self.data.append(x)
        if self.mins == [] or x <= self.mins[-1]:
            self.mins.append(x)

    # @return nothing
    def pop(self):
        if 0 < len(self.data) and self.data.pop() == self.mins[-1]:
            self.mins.pop()

    # @return an integer
    def top(self):
        return self.data[-1]

    # @return an integer
    def getMin(self):
        return self.mins[-1]
