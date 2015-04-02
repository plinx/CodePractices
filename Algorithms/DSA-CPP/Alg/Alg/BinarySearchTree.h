#ifndef BinarySearchTree_h
#define BinarySearchTree_h

template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree() { root = NULL; }
	~BinarySearchTree() { makeEmpty(); }
	//BinarySearchTree(const BinarySearchTree& rhs) {}

	const T& findMin() const;
	const T& findMax() const;
	bool contains(const T& x) const;
	bool isEmpty() const;
	void printTree(int order) const;

	void makeEmpty();
	void insert(const T& x);
	void remove(const T& x);

	const BinarySearchTree& operator=(const BinarySearchTree& rhs) {
		if (this != &rhs) {
			makeEmpty();
			root = clone(rhs.root);
		}
		return *this;
	}

	enum
	{
		PreOrder,
		InOrder,
		PostOrder
	};

private:
	struct BNode
	{
		T element;
		BNode* left;
		BNode* right;

		BNode(const T& e, BNode *lt, BNode* rt)
			: element(e), left(lt), right(rt) {}
	};

	BNode* root;

	bool contains(const T& x, BNode* t) const {
		if (t == NULL)
			return false;
		else if (x < t->element)
			return contains(x, t->left);
		else if (t->element < x)
			return contains(x, t->right);
		else
			return true;
	}
	void insert(const T& x, BNode*& t) const {
		if (t == NULL)
			t = new BNode(x, NULL, NULL);
		else if (x < t->element)
			insert(x, t->left);
		else if (t->element < x)
			insert(x, t->right);

		// x == t->element
		// do nothing
	}
	void remove(const T& x, BNode*& t) const {
		if (t == NULL)
			return;
		else if (x < t->element)
			remove(x, t->left);
		else if (t->element < x)
			remove(x, t->right)
		else if (t->left == NULL && t->right == NULL) {
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		} else {
			BNode* oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}

	}
	BNode* findMin(BNode* t) const {
		if (t == NULL)
			return NULL;
		if (t->left == NULL)
			return t;
		return findMin(t->left);
	}
	BNode* findMax(BNode* t) const {
		if (t != NULL)
			while (t->right != NULL)
				t = t->right;
		return t;
	}
	void makeEmpty(BNode* t) {
		if (t != NULL) {
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = NULL;
	}
	void printTree(int order, BNode* t) const {
		switch (order)
		{
		case PreOrder:
			if (t == NULL) {
				return;
			}
			cout << t->element << " ";
			printTree(order, t->left);
			printTree(order, t->right);
			break;
		case InOrder:
			if (t == NULL) {
				return;
			}
			printTree(order, t->left);
			cout << t->element << " ";
			printTree(order, t->right);
			break;
		case PostOrder:
			if (t == NULL) {
				return;
			}
			printTree(order, t->left);
			printTree(order, t->right);
			cout << t->element << " ";
			break;
		default:
			break;
		}
	}
	BNode* clone(BNode* t) const {
		if (t == NULL)
			return NULL;
		return new BNode(t->element, clone(t->left), clone(t->right));
	}

};

template <typename T>
bool BinarySearchTree<T>::contains(const T& x) const
{
	return contains(x, root);
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
	return root == NULL;
}

template <typename T>
void BinarySearchTree<T>::printTree(int order) const
{
	printTree(order, root);
}

template <typename T>
void BinarySearchTree<T>::insert(const T& x)
{
	insert(x, root);
}

template <typename T>
void remove(const T& x)
{
	remove(x, root);
}

template <typename T>
const T& BinarySearchTree<T>::findMin() const
{
	return findMin(root)->element;
}

template <typename T>
const T& BinarySearchTree<T>::findMax() const
{
	return findMax(root)->element;
}

template <typename T>
void BinarySearchTree<T>::makeEmpty()
{
	makeEmpty(root);
}

#endif