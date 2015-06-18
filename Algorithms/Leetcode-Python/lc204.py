__author__ = 'linx'

from math import sqrt

class Solution(object):
	def countPrimes(self, n):
		if n <= 2:
			return 0
		prime = [1 for i in xrange(n)]

		count = n - 2
		for i in xrange(2, n):
			if prime[i]:
				j = i*i
				while j < n:
					if prime[j]:
						prime[j] = 0
						count -= 1
					j += i

		#print prime
		return count
		pass
	pass

if __name__ == '__main__':
	print Solution().countPrimes(3)
	#print Solution().countPrimes(499979)
