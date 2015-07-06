__author__ = 'linx'

class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e
    pass

class Solution(object):
    def insert(self, intervals, newIntervals):
        if intervals == []:
            return [newIntervals]

        result = []
        head = 0
        while head < len(intervals) and intervals[head].end < newIntervals.start:
            head += 1
        tail = head
        while tail < len(intervals) and intervals[tail].start < newIntervals.end:
            tail += 1
#        print head, tail
        result = intervals[:head]
        if tail != len(intervals):
            if intervals[tail].start <= newInterval.end:
                result += [Interval(min(intervals[head].start, newInterval.start), \
                    intervals[tail].end)]
                tail += 1
        else:
            result += [Interval(min(intervals[head].start, newIntervals.start), \
                max(intervals[tail - 1].end, newIntervals.end))]
        result += intervals[tail:]

        for i in xrange(len(result)):
            print [result[i].start, result[i].end],
        pass
    pass

if __name__ == '__main__':
    in0 = [[0, 9]]
    in1 = [[1, 3], [6, 9]]
    in2 = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]

    intervals = []
    interval = [[1, 5], [8, 15]]
    newInterval = Interval(2, 3)
    for i in xrange(len(interval)):
        intervals.append(Interval(interval[i][0], interval[i][1]))

    for i in xrange(len(intervals)):
        print [intervals[i].start, intervals[i].end],
    print ""
    print "newIntervals : ", [newInterval.start, newInterval.end]
    Solution().insert(intervals, newInterval)


