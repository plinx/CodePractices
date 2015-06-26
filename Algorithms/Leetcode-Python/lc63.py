__author__ = 'linx'

class Solution(object):
	def uniquePath(self, grid):
		m, n = len(grid[0]), len(grid)
		r = [[0 for i in xrange(m)] for j in xrange(n)]
		print r

		for i in xrange(m):
			if grid[0][i] != 1:
				r[0][i] = 1
			else:
				break

		for j in xrange(n):
			if grid[j][0] != 1:
				r[j][0] = 1
			else:
				break

		for j in xrange(1, n):
			for i in xrange(1, m):
				if grid[j][i] != 1:
					r[j][i] = r[j - 1][i] + r[j][i - 1]
				else:
					r[j][i] = 0

		print r
		return r[-1][-1]

		pass
	pass

if __name__ == '__main__':
	grid = [
		[0, 0, 1],
		[1, 0, 0],
		[0, 0, 0]
	]
	print Solution().uniquePath(grid)
	pass
