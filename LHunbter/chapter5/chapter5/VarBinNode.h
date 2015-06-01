#ifndef VarBinNode_h
#define VarBinNode_h

#include <iostream>

struct VarBinNode
{
	virtual ~VarBinNode() = default;
	virtual bool isLeaf() = 0;
	virtual void traverse() = 0;
};

template <typename E>
struct LeafNode : public VarBinNode
{
private:
	E _item;
public:
	LeafNode(const E& item) : _item(item) {}
	bool isLeaf() { return ture; }
	void trverse() { std::cout << "Leaf : " << _item << std::endl; }
};

template <typename E>
struct IntlNode : public VarBinNode
{
private:
	E _item;
	VarBinNode* _left;
	VarBinNode* _right;
public:
	IntlNode(const E& item, VarBinNode* left, VarBinNode* right)
		: _item(item), _left(left), _right(right) {}
	bool isLeaf() { return false; }

	void traverse()
	{
		std::cout << "IntlNode : " << _item << std::endl;
		if (_left != nullptr) _left->traverse();
		if (_right != nullptr) _right->traverse();
	}
};

#endif