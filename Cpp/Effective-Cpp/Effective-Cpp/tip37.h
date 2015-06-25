#ifndef tip37_h
#define tip37_h

class Base {
public:
	enum Order { one, two, three };
	virtual void getOrder(Order order = one) const = 0;
};

class D1 : public Base {
public:
	void getOrder(Order order = two) const {
		std::cout << order << std::endl;
	}
};

class D2 : public Base {
public:
	virtual void getOrder(Order order) const {
		std::cout << order << std::endl;
	}
};

void test37_1()
{
	Base *pb;
	D1 d1;
	D1 *pd1 = new D1();
	Base *pd2 = new D2;
	pd1->getOrder();
	pb = &d1;
	pb->getOrder(Base::three);
	pb->getOrder();
	pb = pd2;
	pb->getOrder(Base::three);
	pb->getOrder();
}

#endif