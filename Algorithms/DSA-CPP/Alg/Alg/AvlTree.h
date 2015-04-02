#ifndef AvlTree_h
#define AvlTree_h


template <typename T>
class AvlTree
{
public:
	AvlTree() = default;
	~AvlTree() = default;

	void insert(const T& x) { insert(x, root); }
	void printTree(int order) { printTree(order, root); }
	int height() { return height(root); }

	enum 
	{
		PreOrder, 
		InOrder, 
		PostOder
	};

private:
	struct AvlNode
	{
		T element;
		AvlNode* left;
		AvlNode* right;
		int height;

		AvlNode(const T& e, AvlNode* lt, AvlNode* rt, int h = 0)
			: element(e), left(lt), right(rt), height(h) {}
	};

	AvlNode* root = NULL;

	int height(AvlNode* t)
	{
		return t == NULL ? -1 : t->height;
	}

	void printTree(int order, AvlNode* t)
	{
		switch (order)
		{
		case PreOrder:
			if (t == NULL)
				return;
			cout << t->element << " ";
			printTree(order, t->left);
			printTree(order, t->right);
			break;
		case InOrder:
			if (t == NULL)
				return;
			printTree(order, t->left);
			cout << t->element << " ";
			printTree(order, t->right);
			break;
		case PostOder:
			if (t == NULL)
				return;
			printTree(order, t->left);
			printTree(order, t->right);
			cout << t->element << " ";
			break;
		default:
			break;
		}
	}

	void insert(const T& x, AvlNode*& t)
	{
		if (t == NULL)
		{
			t = new AvlNode(x, NULL, NULL);
		}
		else if (x < t->element)
		{
			insert(x, t->left);
			if (height(t->left) - height(t->right) == 2)
			{
				if (x < t->left->element)
					rotateLeft(t);
				else
					doubleRotateLeft(t);
			}
		}
		else if (t->element < x)
		{
			insert(x, t->right);
			if (height(t->right) - height(t->left) == 2)
			{
				if (x > t->right->element)
					rotateRight(t);
				else
					doubleRotateRight(t);
			}
		}
		//else
			// do nothing
		t->height = std::max(height(t->left), height(t->right)) + 1;
	}

	void rotateLeft(AvlNode*& k2)
	{
		AvlNode* k1 = k2->left;
		
		k2->left = k1->right;
		k1->right = k2;

		k2->height = std::max(height(k2->left), height(k2->right)) + 1;
		k1->height = std::max(height(k1->left), k2->height) + 1;

		k2 = k1;
	}

	void rotateRight(AvlNode*& k1)
	{
		AvlNode* k2 = k1->right;

		k1->right = k2->left;
		k2->left = k1;

		k1->height = std::max(height(k1->left), height(k1->right)) + 1;
		k2->height = std::max(k1->height, height(k2->right)) + 1;

		k1 = k2;
	}

	void doubleRotateLeft(AvlNode*& k3)
	{
		rotateRight(k3->left);
		rotateLeft(k3);
	}

	void doubleRotateRight(AvlNode*& k3)
	{
		rotateLeft(k3->right);
		rotateRight(k3);
	}

};



#endif