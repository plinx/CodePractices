__author__ = 'linx'

class Sulotion(object):
	def numTrees(self, n):
		r = [0] * (n + 1)
		r[0], r[1] = 1, 1
		for i in xrange(2, n + 1):
			for j in xrange(1, i + 1):
				r[i] += r[j - 1] * r[i - j]
		return r[n]
		pass
	pass

if __name__ == '__main__':
	print Sulotion().numTrees(2)
	pass
