__author__ = 'linx'

class Craetivity(object):
    # C1.13
    def reverse(self, data):
        rdata = data
        for i in range(len(rdata) / 2):
            rdata[i], rdata[-i - 1] = rdata[-i - 1], rdata[i]

        return rdata

    # C1.14
    def check_odd(self, data):
        for d in data:
            if d % 2 == 1:
                return True

        return False

    # sleep now!

