__author__ = 'linx'

class Tokenizer(object):
    # class macro
    _MACRO = [
        "TOKEN_SUCCESS",    # 0
        "FORMAT_ERROR",     # 1
    ]

    def __init__(self):
        # tokens table
        self._tokens = []
        # Debug Mode On/Off : 1/0
        self._DEBUG = False

    def token(self):
        return self._tokens

    def debug_print(self, msg):
        if self._DEBUG == True:
            print msg,

    """
    fpath : file path string
    _tokens : tokens table
    """
    def read(self, fpath):
        symbol = ['(', ')', '{', '}', "+", "-", "*", "/"]
        with open(fpath, "r") as file:
            lineNum = 0
            text_flag = 0
            for lines in file.readlines():
                lineStr = "Line %d :\t" % lineNum
                self.debug_print(lineStr)
                start = 0

                for index in xrange(len(lines)):
                    previ = index - 1 if index > 0 else 0
                    # text content
                    if lines[index] == '\"':
                        if text_flag == 0: # text_flag == 0, text content start
                            if lines[previ] != ' ' and lines[previ] not in symbol:
                                print lines,
                                self.debug_print(''.join(' ' for i in xrange(len(lineStr))))
                                self.debug_print('\t')
                                print ''.join(' ' for i in xrange(previ)), '^'
                                return self._MACRO[1] # FORMAT_ERROR
                            text_flag = 1
                        else: # text_flag == 1:  text content end
                            self.debug_print("'%c'" % lines[start - 1])
                            self._tokens.append(lines[start - 1])
                            self.debug_print("'%s'" % lines[start:index])
                            self._tokens.append(lines[start:index])
                            self.debug_print("'%c'" % lines[index])
                            self._tokens.append(lines[index])
                            text_flag = 0
                        start = index + 1

                    if text_flag == 1: # continue in text context
                        continue

                    if lines[index] == '#':
                        self.debug_print(lines[index:-1]),
                        self.debug_print("'\\n'")
                        self.debug_print("\n")
                        break # skip the comment line
                    elif lines[index] == ' ':
                        if lines[previ] == '\"':
                            continue
                        elif lines[previ] != ' ' and lines[previ] not in symbol:
                            self.debug_print("'%s'" % lines[start:index])
                            self._tokens.append(lines[start:index])
                    elif lines[index] in symbol:
                        if lines[previ] == '\"':
                            #self._tokens.append(lines[start:index])
                            pass
                        elif lines[previ] != ' ' and lines[previ] not in symbol:
                            self.debug_print("'%s'" % lines[start:index])
                            self._tokens.append(lines[start:index])
                        self.debug_print("'%c'" % lines[index])
                        self._tokens.append(lines[index])

                    else: #if lines[index] not in symbol:
                        if lines[index] == '\n':
                            if index == 0:
                                pass
                            elif lines[previ] not in symbol:
                                self.debug_print("'%s'" % lines[start:index])
                                self._tokens.append(lines[start:index])
                            self.debug_print("'\\n'")
                            self.debug_print("\n")
                            self._tokens.append("\n")
                        if lines[previ] == ' ' or lines[previ] in symbol:
                            start = index

                lineNum += 1
                #self.debug_print("\n")
        return self._MACRO[0]

    pass

if __name__ == '__main__':
    token = Tokenizer()
    print token.read("hello.txt")

    for t in token.token():
        print "'%s'" % t,
