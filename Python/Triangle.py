# -*- coding: utf-8 -*-

import sys, random
from math import ceil as ceil
from PyQt4 import QtGui, QtCore

class Triangle(object):
	class Point(object):
		def __init__(self, x, y):
			self.x = x
			self.y = y
		pass

	def __init__(self, x1, y1, x2, y2, x3, y3):
		self.p1 = self.Point(x1, y1)
		self.p2 = self.Point(x2, y2)
		self.p3 = self.Point(x3, y3)
		self._sort()

	def _sort(self):
		if self.p3.y < self.p1.y:
			self.p1, self.p3 = self.p3, self.p1
		if self.p2.y < self.p1.y:
			self.p1, self.p2 = self.p2, self.p1
		if self.p3.y < self.p2.y:
			self.p2, self.p3 = self.p3, self.p2
		print self.p1.y, self.p2.y, self.p3.y

class Window(QtGui.QWidget):
	def __init__(self, width, height):
		self._width = width
		self._height = height

		super(Window, self).__init__()
		self.resize(self._width, self._height)
		self.setWindowTitle('Triangle')
		self.show()

	def paintEvent(self, event):
		self.painter = QtGui.QPainter()
		self.painter.begin(self)
		self.drawTriangle(self.painter);
		self.painter.end()

	def drawTriangle(self, painter):
		tri = Triangle(100.0, 300.0, 200.0, 400.0, 300.0, 100.0)
		painter.setBrush(QtGui.QColor(0, 0, 0))
		painter.drawRect(0, 0, self._width, self._height)

		clip = Triangle.Point(0, 0)
		clip.y = tri.p2.y
		clip.x = tri.p1.x + (clip.y - tri.p1.y) * (tri.p3.x - tri.p1.x) / (tri.p3.y - tri.p1.y)
		print (tri.p2.x, tri.p2.y), (clip.x, clip.y), (tri.p3.x, tri.p3.y)
		self.drawFlatBottomTriangle(painter, tri.p2, clip, tri.p3)
		self.drawFlatTopTriangle(painter, tri.p1, tri.p2, clip)
		painter.setPen(QtGui.QColor(255, 255, 255))
		painter.drawPoint(100, self._height - 100)

	def drawFlatBottomTriangle(self, painter, p1, p2, p3):
		if p3.y > self._height:
			top = self._height
		else:
			top = p3.y

		if p1.y < 0:
			bottom = 0
		else:
			bottom = p1.y
		
		# draw flat bottom triangle
		for y in range(int(bottom), int(top)):
			scan_lx  = p1.x + (y - p1.y) * (p3.x - p1.x) / (p3.y - p1.y)
			scan_rx  = p2.x + (y - p2.y) * (p3.x - p2.x) / (p3.y - p2.y)
			for x in range(int(scan_lx), int(scan_rx)):
				#if y > p1.y and y < p3.y:
				#	if x > scan_lx and x < scan_rx:
				painter.setPen(QtGui.QColor(255, 0, 0))
				painter.drawPoint(x, self._height - y)

	def drawFlatTopTriangle(self, painter, p1, p2, p3):
		if p3.x < p2.x:
			p2, p3 = p3, p2

		if p3.y > self._height:
			top = self._height
		else:
			top = p3.y

		if p1.y < 0:
			bottom = 0
		else:
			bottom = p1.y

		# draw flat top triangle
		for y in range(int(bottom), int(top)):
			scan_lx = p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y)
			scan_rx = p1.x + (y - p1.y) * (p3.x - p1.x) / (p3.y - p1.y)
			for x in range(int(scan_lx), int(scan_rx)):
				painter.setPen(QtGui.QColor(0, 0, 255))
				painter.drawPoint(x, self._height - y)


def main():
	app = QtGui.QApplication(sys.argv)
	win = Window(400, 400)
	sys.exit(app.exec_())

if __name__ == '__main__':
	main()