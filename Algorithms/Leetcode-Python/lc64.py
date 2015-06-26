__author__ = 'linx'

class Solution(object):
	def minPathSum(self, grid):
		m, n = len(grid[0]), len(grid)
		r = [[0 for i in xrange(m)] for j in xrange(n)]
		r[0][0] = grid[0][0]
		for i in xrange(1, m):
			r[0][i] = r[0][i - 1] + grid[0][i]
		for j in xrange(1, n):
			r[j][0] = r[j - 1][0] + grid[j][0]

		for j in xrange(1, n):
			for i in xrange(1, m):
				r[j][i] = min(grid[j][i] + r[j - 1][i], grid[j][i] + r[j][i - 1])

		for j in xrange(n):
			print grid[j]
		print ""
		for j in xrange(n):
			print r[j]
		return r[- 1][- 1]
		pass
	pass

if __name__ == '__main__':
	grid = [
		[1, 1, 1, 1],
		[2, 2, 2, 2],
		[1, 1, 1, 1]
	]
	print Solution().minPathSum(grid)
	pass
