__author__ = 'linx'

class Greedy(object):
    def recursive_activity_selector(self, s, f, k):
        m = k + 1
        while m < len(s) and s[m] < f[k]:
            m = m + 1

        if m <= len(s):
            return [[s[k], f[k]]] + \
                   self.recursive_activity_selector(s, f, m)
        return []
        pass

    def greedy_activity_selector(self, s, f):
        result = [[s[0], f[0]]]
        for i in xrange(1, len(s)):
            if result[-1][-1] < s[i]:
                result.append([s[i], f[i]])

        return result
        pass

    def dp_greedy_activity(self, s, f):
        n = len(s)
        r = [[] for i in xrange(n + 1)]

        rindex = 0
        for j in xrange(n):
            r[j].append([s[j], f[j]])
            for i in xrange(j + 1, n):
                if r[j][-1][-1] < s[i]:
                    r[j].append([s[i], f[i]])
            if len(r[rindex]) < len(r[j]):
                rindex = j

        return r[rindex]
        pass

    def greedy_activity_night(self, s, f):
        result = [[s[-1], f[-1]]]

        for i in xrange(len(s) - 2, -1, -1):
            if f[i] < result[0][0]:
                result.insert(0, [s[i], f[i]])

        return result
        pass

    def dp_knapsack(self, s, w):
        n = len(s)
        r = [[0 for i in xrange(w + 1)] for j in xrange(n + 1)]

        rw = 0
        for j in xrange(1, n + 1):
            #print s[j - 1],
            for i in xrange(1, w + 1):
                if i < s[j - 1][0]:
                    r[j][i] = r[j - 1][i]
                elif r[j - 1][i] < r[j - 1][i - s[j - 1][0]] + s[j - 1][1]:
                    r[j][i] = r[j - 1][i - s[j - 1][0]] + s[j - 1][1]
                else:
                    r[j][i] = r[j - 1][i]

            #print r[j]

        return r[-1][-1]
        pass

    def greedy_knapsack_decrease(self, s, w):
        n = len(s) - 1
        while 0 < n and w < s[n][0]:
            n -= 1

        result = []
        while 0 <= n and 0 <= w:
            if s[n][0] <= w:
                result.append(s[n])
                w -= s[n][0]
            n -= 1

        return sum(result[i][1] for i in xrange(len(result)))
        pass

    class TreeNode(object):
        def __init__(self, x):
            self.weight = x
            self.char = None
            self.left = None
            self.right = None
        pass
    def huffman(self, s):
        queue = []
        for i in xrange(len(s)):
            queue.append(self.TreeNode(s[i][1]))
            queue[-1].char = s[i][0]

        while 1 < len(queue):
            node = self.TreeNode(0)
            if queue != []:
                node.left = queue[0]
                node.weight += node.left.weight
                queue.pop(0)
            if queue != []:
                node.right = queue[0]
                node.weight += node.right.weight
                queue.pop(0)
            for i in xrange(len(queue)):
                if queue[i].weight < node.weight:
                    continue
                else: # node.weight < queue[i].weight
                    queue.insert(i, node)
                    node = None
                    break
            if node != None:
                queue.append(node)

        return queue[0]
        pass

    def preorder_travel(self, root):
        if root == None:
            return
        if root.char != None:
            print [root.char, root.weight],
        else:
            print root.weight,
        self.preorder_travel(root.left)
        self.preorder_travel(root.right)
        pass

    pass
