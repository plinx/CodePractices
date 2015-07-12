#ifndef Component_h
#define Component_h

class Component
{
public:
	Component() = default;
	virtual ~Component() = 0;

	virtual void Operation() = 0;
	virtual void Add(Component*) {}
	virtual void Remove(Component*) {}
	virtual Component* getChild(int) { return nullptr; }
};
Component::~Component() = default;

class Leaf : public Component
{
public:
	Leaf() = default;
	void Operation() { std::cout << "Leaf Operation." << std::endl; }
};

class EmptyLeaf : public Component
{
public:
	EmptyLeaf() = default;
	void Operation() { std::cout << "Leaf not found." << std::endl; }
};
#endif