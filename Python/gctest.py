#!/usr/bin/env python

import gc
import sys

class TreeNode(object):
	def __init__(self, elem, lchild, rchild):
		self._elem = elem
		self._lchild = lchild
		self._rchild = rchild

	def set_lchild(self, lchild):
		self._lchild = lchild

if __name__ == '__main__':
	gc.set_debug(gc.DEBUG_STATS | gc.DEBUG_LEAK)
	a = TreeNode(1, None, None)
	b = TreeNode(2, None, None)
	c = TreeNode(3, None, None)

	print "a ref : ", sys.getrefcount(a)
	print "b ref : ", sys.getrefcount(b)
	print "c ref : ", sys.getrefcount(c)
	a.set_lchild(b)
	b.set_lchild(c)
	a.set_lchild(c)
	gc.collect()
	
	print "a ref : ", sys.getrefcount(a)
	print "b ref : ", sys.getrefcount(b)
	print "c ref : ", sys.getrefcount(c)
