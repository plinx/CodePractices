class Any(object):
    def __getattr__(self, name, *args):
    	print name
    	return lambda *args : self.__getattr__(args)

if __name__ == "__main__":
	any = Any()
	any.fuck(1, 2, 3)
	any.shit([1, 2, 3], 'fuck you pussy')
	any.suck('make me juzz in pants baby.')