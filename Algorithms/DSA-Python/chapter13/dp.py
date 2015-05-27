__author__ = 'linx'

class DP(object):
    def LCS(self, X, Y):
        n, m = len(X), len(Y)
        L = [[0] * (m + 1) for k in xrange(n + 1)]
        for j in xrange(n):
            for k in xrange(m):
                if X[j] == Y[k]:
                    L[j + 1][k + 1] = L[j][k] + 1
                else:
                    L[j + 1][k + 1] = max(L[j][k + 1], L[j + 1][k])
        return L

    def LCS_solution(self, X, Y, L):
        solution = []
        j, k = len(X), len(Y)
        while L[j][k] > 0:
            if X[j - 1] == Y[k - 1]:
                solution.append(X[j - 1])
                j -= 1
                k -= 1
            elif L[j - 1][k] >= L[j][k - 1]:
                j -= 1
            else:
                k -= 1
        return ''.join(reversed(solution))

    # wrong LCS, missing horizon counts
    def lin_LCS(self, X, Y):
        n, m = len(X), len(Y)
        L = [[0] * (m + 1) for k in xrange(n + 1)]
        pos = 0
        for j in xrange(n):
            L[j + 1][pos:m + 1] = [L[j][pos]] * (m - pos + 1)
            #print j, L[j + 1][pos + 1:m + 1], pos
            for k in xrange(pos, m):
                if X[j] == Y[k]:
                    L[j + 1][k + 1:m + 1] = [L[j][k + 1] + 1] * (m - k)
                    pos = k + 1
                    #print j, k, pos
                    break

        return L

    def lin_LCS_solution(self, X, Y, L):
        solution = []
        j, k = len(X), len(Y)
        #print L
        #print j, k, L[j][k], X[j - 1]
        while L[j][k] > 0:
            if X[j - 1] == Y[k - 1]:
                if L[j][k - 1] == 0 and L[j - 1][k] != 0:
                    #print j, k, L[j][k], L[j - 1][k - 1]
                    j -= 1
                    continue
                solution.append(X[j - 1])
                j -= 1
                k -= 1
            elif L[j][k - 1] != 0:
                k -= 1
            else:
                j -= 1

        return ''.join(reversed(solution))


    pass
