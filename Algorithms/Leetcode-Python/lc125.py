__author__ = 'linx'

class Solution(object):
    def isPalindrome(self, s):
        if len(s) < 1:
            return True

        i, j = 0, len(s) - 1
        s = s.upper()
        while i < j:
            # ord('A') = 65, ord('Z') = 90
            # ord('0') = 48, ord('9') = 57
            ords = ord(s[i])
            if ords < 48 or 57 < ords < 65 or 90 < ords:
                i += 1
                continue
            ords = ord(s[j])
            if ords < 48 or 57 < ords < 65 or 90 < ords:
            #if ord(s[j]) < 65 or 90 < ord(s[j]):
                j -= 1
                continue

            #print s[i], s[j]
            if s[i] == s[j]:
                i += 1
                j -= 1
            else:
                return False

        return True

        pass
    pass

if __name__ == '__main__':
    #s = "A man, a plan, a canal: Panama"
    #s = "race a car"
    #s = "1a2"
    s = "0k.;r0.k"
    print Solution().isPalindrome(s)
    pass
