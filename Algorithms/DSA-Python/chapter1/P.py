__author__ = 'linx'

class Project(object):
    # P1.29
    def str_perm(self, table, start):
        if start == len(table) - 1:
            s = ''
            for t in table:
                s += t
            print s,
        else:
            for i in range(start, len(table)):
                table[start], table[i] = table[i], table[start]
                self.str_perm(table, start + 1)
                table[start], table[i] = table[i], table[start]

    # P1.30
    def divide_two(self, data):
        n = 0
        while data >= 2:
            data = data / 2.0
            n += 1
        return n

    # P1.31
    def calculator(self):
        while True:
            str = raw_input("calculator (input quit to exit): ")
            if str == "quit":
                break
            elif str.find(' ') == -1:
                print "Input sample : value1 (space) operator (space) value2"
                continue
            else:
                str = str.split(' ')
                if len(str) != 3:
                    print "Input sample : value1 (space) operator (space) value2"
                    continue
                else:
                    num1, op, num2 = str
                    if num1 == '' or op == '' or num2 == '':
                        print "Input sample : value1 (space) operator (space) value2"
                        continue

                    num1, num2 = float(num1), float(num2)
                    if op == '+' :
                        print "ans = %f" % (num1 + num2)
                    elif op == '-' :
                        print "ans = %f" % (num1 - num2)
                    elif op == '*' :
                        print "ans = %f" % (num1 * num2)
                    elif op == '/' :
                        print "ans = %f" % (num1 / num2)
                    else:
                        print "operator support +-*/ only."

    # P1.33
    # skip

    # P1.34
    # len(table) = 8
    # table[randint(1, 8)]

    # P1.35
    # skip

    # P1.36
    # for loop to count the words
