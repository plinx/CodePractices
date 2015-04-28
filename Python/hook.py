from multiprocessing import Process, Queue
import os, time, random

import pythoncom
import pyHook
import win32api
import win32con

class PublicData(object):
	def __init__(self):
		self._x = 0
		self._y = 0

	@property
	def x(self):
	    return self._x

	@x.setter
	def x(self, value):
		x, y = win32api.GetCursorPos()
		if value != x:
			self._x = x
			print "data fixed", " x : ", self._x
		else:
			self._x = value
			print "x : ", self._x
	
	@property
	def y(self):
	    return self._y

	@y.setter
	def y(self, value):
		x, y = win32api.GetCursorPos()
		if value != y:
			self._y = y
			print "data fixed", " y : " , self._y
		else:
			self._y = value
			print "y : ", self._y

	pass
	
data = PublicData()

def onClick(event):
	print "onClick HookEvent"
	x, y = event.Position
	print "Hook Position : ", (x, y)
	print "Hook redirect Position : ", (x + 10, y + 10)
	#data.x = x
	#data.y = y
	data.x = x + 10
	data.y = y + 10
	return True

def write(q):
    #for value in ['A', 'B', 'C']:
    #    print 'Put %s to queue...' % value
    #    q.put(value)
    #    time.sleep(random.random())
	hm = pyHook.HookManager()
	hm.SubscribeMouseLeftDown(onClick)
	hm.HookMouse()
	pythoncom.PumpMessages() 
	q.value()

def read(q):
    while True:
        value = q.get(True)
        print 'Get %s from queue.' % value

if __name__ == "__main__":
	#hm = pyHook.HookManager()
	#hm.SubscribeMouseLeftDown(onClick)
	#hm.HookMouse()
	#pythoncom.PumpMessages() 
	q = Queue()
	pw = Process(target=write, args=(q,))
	pr = Process(target=read, args=(q,))
	pw.start()
	pr.start()
	pw.join()
	pr.terminate()

