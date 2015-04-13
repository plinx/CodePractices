#ifndef Template_h
#define Template_h

class TemplateClass
{
public:
	virtual ~TemplateClass() = default;
	void TemplateMethod() {
		this->PrimitiveOperation1();
		this->PrimitiveOperation2();
	}
protected:
	virtual void PrimitiveOperation1() = 0;
	virtual void PrimitiveOperation2() = 0;
	TemplateClass() = default;
};

class ConcreteClass1 : public TemplateClass
{
public:
	ConcreteClass1() = default;
	~ConcreteClass1() = default;
protected:
	void PrimitiveOperation1() { std::cout << "ConcreteClass1 PrimitiveOperation1" << std::endl; }
	void PrimitiveOperation2() { std::cout << "ConcreteClass1 PrimitiveOperation2" << std::endl; }
};

class ConcreteClass2 : public TemplateClass
{
public:
	ConcreteClass2() = default;
	~ConcreteClass2() = default;
protected:
	void PrimitiveOperation1() { std::cout << "ConcreteClass2 PrimitiveOperation1" << std::endl; }
	void PrimitiveOperation2() { std::cout << "ConcreteClass2 PrimitiveOperation2" << std::endl; }
};

#endif