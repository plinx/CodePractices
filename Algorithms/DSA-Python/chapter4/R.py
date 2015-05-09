__author__ = 'linx'

class Reinforcement(object):
    """ R4.1
    running time: O(n)
    space usage : O(1)
    input : table
    output : maximum element
    """
    def find_max(self, table):
        max = table[0]
        for i in xrange(1, len(table)):
            if max < table[i]:
                max = table[i]

        return max

    """ R4.2
    power(2, 5)
    -> power(2, 4)
    -> ... -> power(2, 0) | backup
    """

    """ R4.3
    power(2, 18) | power(2, 9)**2
    -> power(2, 9) | 2 * power(2, 4)**2
    -> power(2, 4) | power(2, 2)**2
    -> power(2, 2) | power(2, 1)**2
    -> power(2, 1) | 2 * power(2, 0)**2 | 2 * 1**2 | backup
    """

    """ R4.4
    reverse(S, 0, 5)
    -> reverse(S, 1, 4)
    -> ... -> reverse(S, 2, 3) | backup
    """

    # R4.5
    # skip

    """ R4.6
    H(n) => 1/n + H(n - 1)
    H(n - 1) => 1/(n - 1) + H(n - 2)
    ... => H(2) => 1/2 + 1
    """

    """ R4.7
    13531   | index = 0, len = 5, (len - index) % 3 != 0 | print 1
    3531    | index = 1, len = 5, (len - index) % 3 != 0 | print 3
    531     | index = 2, len = 5, (len - index) % 3 == 0 | print ,5
    31      | index = 3, .......................... != 0 | print 3
    1       | index = 4, .......................... != 0 | print 1
    """

    # R4,8
    # running time : O(log(n))

    pass