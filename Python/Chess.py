#!/usr/bin/env python
# -*- coding: utf-8 -*-

from multiprocessing import Process, Queue
import os, time, msvcrt

class Chess(object):
	class Player(object):
		pass

	def __init__(self):
		num = raw_input("Enter chess table size (n x n): ")
		self._num = int(num) + 1;
		self._pos_x = self._pos_y = self._num / 2;
		self._table = [[u'╋' for row in range(self._num)] for column in range(self._num)]

		for row in range(self._num):
			self._table[row][0] = str(row) + '\t'
			if row != 0:
				self._table[row][1] = u'┣'
				self._table[row][self._num - 1] = u'┫'
		for column in range(self._num):
			self._table[0][column] = str(column) + ' '
			if column != 0:
				self._table[1][column] = u'┳'
				self._table[self._num - 1][column] = u'┻'

		self._table[0][0] = '\t'
		self._table[1][1] = u'┏'
		self._table[1][self._num - 1] = u'┓'
		self._table[self._num - 1][1] = u'┗'
		self._table[self._num - 1][self._num - 1] = u'┛'

		self._player1 = self.Player()
		self._player1.piece = u'◇'
		self._player1.name = raw_input("Enter player1's name: ")
		self._player2 = self.Player()
		self._player2.piece = u'◆'
		self._player2.name = raw_input("Enter player2's name: ")

		self._curr_player = self._player1
		os.system('cls')
		self._show()

	def _show(self):
		for i in range(self._num):
			print '       ',
			for j in range(self._num):
				if self._table[i][j] == u'◇' or self._table[i][j] == u'◆' \
				or i != self._pos_x or j != self._pos_y:
					print self._table[i][j],
				else:
					print u'※',
			print ''

		print '\t', 'Player1 ' + self._player1.piece + ': ' + self._player1.name,
		print '  |  ', 'Player2 ' + self._player2.piece + ': ' + self._player2.name
		print '\tCursor Postion: ', self._pos_x, self._pos_y

	def _moveCursor(self, step):
		if step == 75: # left key
			if self._pos_y > 1:
				self._pos_y = self._pos_y - 1
		if step == 77: # right key
			if self._pos_y < self._num - 1:
				self._pos_y = self._pos_y + 1
		if step == 72: # up key
			if self._pos_x > 1:
				self._pos_x = self._pos_x - 1
		if step == 80: # down key
			if self._pos_x < self._num - 1:
				self._pos_x = self._pos_x + 1

	def _place(self):
		if self._table[self._pos_x][self._pos_y] == u'◇' or \
			self._table[self._pos_x][self._pos_y] == u'◆':
			return

		if self._curr_player == self._player1:
			self.winner = self._curr_player
			self._curr_player = self._player2
			self._table[self._pos_x][self._pos_y] = u'◇'
		else: 
			self.winner = self._curr_player
			self._curr_player = self._player1
			self._table[self._pos_x][self._pos_y] = u'◆'

	def _judge(self):
		# pos : left, up, right, down, left-up, left-down, right-up, right-down
		lpos, upos, rpos, dpos, lupos, ldpos, rupos, rdpos = 1, 1, 1, 1, 1, 1, 1, 1
		# count : vertical, horizon, left-oblique, right-oblique
		vc, hc, loc, roc = 1, 1, 1, 1
		for dist in range(1, 5):
			# vetical count
			if upos != -1 and self._pos_x - dist > 0:
				if self._table[self._pos_x - dist][self._pos_y] \
				== self._table[self._pos_x][self._pos_y]:
					if vc == 5:
						return vc
					vc = vc + 1
				else:
					upos = -1
			if dpos != -1 and self._pos_x + dist < self._num:
				if self._table[self._pos_x + dist][self._pos_y] \
				== self._table[self._pos_x][self._pos_y]:
					if vc == 5:
						return vc;
					vc = vc + 1
				else:
					dpos = -1

			# horizon count
			if lpos != -1 and self._pos_y - dist > 0:
				if self._table[self._pos_x][self._pos_y - dist] \
				== self._table[self._pos_x][self._pos_y]:
					if hc == 5:
						return hc
					hc = hc + 1
				else:
					lpos = -1
			if rpos != -1 and self._pos_y + dist < self._num:
				if self._table[self._pos_x][self._pos_y + dist] \
				== self._table[self._pos_x][self._pos_y]:
					if hc == 5:
						return hc
					hc = hc + 1
				else:
					rpos = -1

			# left-oblique count
			if lupos != -1 and self._pos_x - dist > 0 and self._pos_y - dist > 0:
				if self._table[self._pos_x - dist][self._pos_y - dist] \
				== self._table[self._pos_x][self._pos_y]:
					if loc == 5:
						return vc
					loc = loc + 1
				else:
					lupos = -1
			if rdpos != -1 and self._pos_x + dist < self._num and self._pos_y + dist < self._num:
				if self._table[self._pos_x + dist][self._pos_y + dist] \
				== self._table[self._pos_x][self._pos_y]:
					if loc == 5:
						return loc;
					loc = loc + 1
				else:
					rdpos = -1

			# right-oblique count
			if rupos != -1 and self._pos_x + dist < self._num and self._pos_y - dist > 0:
				if self._table[self._pos_x + dist][self._pos_y - dist] \
				== self._table[self._pos_x][self._pos_y]:
					if roc == 5:
						return vc
					roc = roc + 1
				else:
					rupos = -1
			if ldpos != -1 and self._pos_x - dist > 0 and self._pos_y + dist < self._num:
				if self._table[self._pos_x - dist][self._pos_y + dist] \
				== self._table[self._pos_x][self._pos_y]:
					if roc == 5:
						return loc;
					roc = roc + 1
				else:
					ldpos = -1
			
		return max(vc, hc, loc, roc)


	def mainLoop(self):
		while True:
			key = ord(msvcrt.getch())
			if key == 224: # move cursor
				key = ord(msvcrt.getch())
				self._moveCursor(key)
				os.system('cls')
			elif key == 27: # ESC to break
				break
			elif key == 13: # Enter to place
				self._place()
				os.system('cls')
				if self._judge() == 5:
					print '\t\t\t' + self.winner.name + " Win the Game"
					print ''
					self._show()
					break
			self._show()

	pass

if __name__ == '__main__':
	table = Chess()
	table.mainLoop()
