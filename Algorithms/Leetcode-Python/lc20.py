__author__ = 'linx'

class Solution(object):
	def isValid(self, s):
		stack = []
		left, right = "({[", ")}]"
		for i in xrange(len(s)):
			if s[i] in left:
				stack.append(left.find(s[i]))
			elif s[i] in right:
				if s[i] != right[stack[-1]]:
					return False
				stack.pop()

		if stack != []:
			return False
		return True

		pass
	pass

def main():
	string = "(abasd{asdf})"
	print Solution().isValid(string)

	pass

if __name__ == '__main__':
	main()
