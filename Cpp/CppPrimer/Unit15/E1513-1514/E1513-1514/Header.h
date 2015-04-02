class base {
public:
	base() = default;
	base(std::string &b) : basename(b) {}
	std::string name() { return basename; }
	virtual void print(std::ostream &os) { os << basename << std::endl; }

private:
	std::string basename;
};

class derived : public base {
public:
	derived() = default;
	derived(int di) : i(di) {}
	void print(std::ostream &os) {
		//print(os);				// error calling print(os)
		base::print(os);			// force to use base::print 
		os << " " << i << std::endl;
	}
private:
	int i;
};