#ifndef BSTNode_h
#define BSTNode_h

template <typename E>
struct BinNode
{
	virtual ~BinNode() = default;

	virtual E& elem() = 0;
	virtual void setElem(const E&) = 0;
	virtual BinNode* left() const = 0;
	virtual void setLeft(BinNode*) = 0;
	virtual BinNode* right() const = 0;
	virtual void setRight(BinNode*) = 0;
	virtual void isLeaf() = 0;
};

template <typename Key, typename E>
struct BSTNode : public BinNode<E>
{
private:
	Key _key;
	E _item;
	BSTNode* _left;
	BSTNode* _right;

public:
	BSTNode() : _left(nullptr), _right(nullptr) {}
	BSTNode(Key key, E item, BSTNode* left = nullptr, BSTNode* right = nullptr)
		: _key(key), _item(item), _left(left), _right(right) {}
	~BSTNode() = default;

	E& elem() { return _item; }
	void setElem(cosnt E& item) { _item = item; }
	Key& key() { return _key; }
	void setKey(const Key& key) { _key = key; }

	BSTNode* left() const { return _left; }
	void setLeft(BinNode<E>* left) { _left = (BSTNode*)left; }
	BSTNode* right() const { return _right; }
	void setRight(BinNode<E>* right) { _right = (BSTNode*)right; }

	bool isLeaf() { return (_left == nullptr) && (_right == nullptr); }
};

#endif
