__author__ = 'linx'

class Solution(object):
    def addBinary(self, a, b):
        i = len(a) - 1
        j = len(b) - 1
        c = ""
        inc = "0"
        while 0 <= i and 0 <= j:
            if a[i] == b[j]:
                c = inc + c
                inc = a[i]
            else: # a[i] != b[j]
                c = ("0" if inc == "1" else "1") + c
                # inc no change
            i -= 1
            j -= 1

        while 0 <= i:
            if inc != "1":
                c = a[i] + c
            else: # inc == "1"
                c = ("0" if a[i] == "1" else "1") + c
                inc = a[i]
            i -= 1

        while 0 <= j:
            if inc != "1":
                c = b[j] + c
            else: # inc == "1"
                c = ("0" if b[j] == "1" else "1") + c
                inc = b[j]
            j -= 1

        if inc != "0":
            c = inc + c

        return c

        pass
    pass

if __name__ == '__main__':
    a = "11"
    b = "1"
    print Solution().addBinary(a, b)
    pass
