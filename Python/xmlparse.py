def coroutine(func):
    def start(*args, **kwargs):
        cr = func(*args, **kwargs)
        cr.next()
        return cr
    return start

class Parse(object):
    def __init__(self, fname):
        self._fd = open(fname)
        self._stack = []

    def token(self):
        for line in self._fd:
            si, ei = 0, 0
            for i in xrange(len(line)):
                if '<' == line[i]:
                    si = i
                    if ei < si:
                        #yield line[ei + 1:si],
                        #self.parse(line[ei + 1:si])
                        self.parse().send(line[ei + 1:si])
                elif '>' == line[i]:
                    ei = i
                    #yield line[si + 1:ei],
                    self.parse().send(line[si:ei])
            if si == ei:
                #yield line[:-1],
                self.parse().send(line[:-1])

    @coroutine
    def parse(self):
        while True:
            text = (yield)
            if 0 == len(text):
                continue
            if '<' == text[0]:
                if '/' == text[1]:
                    #self._stack.pop()
                    self.handler().send(('end', text[2:]))
                else:
                    #self._stack.append(text[1:])
                    self.handler().send(('start', text[1:]))
            else:
                self.handler().send(('text', text))

    @coroutine
    def handler(self):
        while True:
            elemtype, text = (yield)
            outstr = ""
            if elemtype == "start":
                if self._stack != []:
                    outstr += '\n' + ''.join(['\t' for i in xrange(len(self._stack) + 1)])
                outstr += "%s :" % text
                self._stack.append(text)
                print outstr,
            elif elemtype == "text":
                print text,
            elif elemtype == "end":
                self._stack.pop()
                #print self._stack,
                outstr += ''.join(['\t' for i in xrange(len(self._stack))])
                print outstr,

    def out(self):
        self.token()
    pass

if __name__ == '__main__':
    parse = Parse("test.xml")
    parse.out()

    pass