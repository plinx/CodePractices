#include "UnitTest.h"

enum
{
	PreOrder,
	InOrder,
	PostOder
};

void AutoTest()
{
	cout << "======= Algorithm Auto Test start =======" << endl;
	Bst_Test();
	Avl_Test();
	cout << "=======  Algorithm Auto Test end  =======" << endl;
}

void Bst_Test()
{
	BinarySearchTree<int> bst;
	treeInsert(bst);
	cout << "BinarySearchTree" << endl;
	cout << "PreOrder : ";
	bst.printTree(PreOrder); cout << endl;
	cout << "InOrder : ";
	bst.printTree(InOrder); cout << endl;
	cout << "PostOrder : ";
	bst.printTree(PostOder); cout << endl;
}

void Avl_Test()
{
	AvlTree<int> avlt;
	treeInsert(avlt);
	cout << "AvlTree" << endl;
	cout << "PreOrder : ";
	avlt.printTree(PreOrder); cout << endl;
	cout << "InOrder : ";
	avlt.printTree(InOrder); cout << endl;
	cout << "PostOrder : ";
	avlt.printTree(PostOder); cout << endl;
	cout << "AvlTree height : " << avlt.height() << endl;
}

template <typename T>
void treeInsert(T& tree)
{
	tree.insert(6);
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	tree.insert(5);
	tree.insert(4);
	tree.insert(8);
	tree.insert(9);
	tree.insert(7);
}
