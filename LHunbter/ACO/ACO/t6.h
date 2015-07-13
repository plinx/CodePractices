#ifndef t6_h
#define t6_h

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int ival) : val(ival), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(int* preorder, int* inorder, int sp, int ep, int si, int ei)
{
	if (ep < sp || ei < si) return nullptr;
	if (sp == ep) return new TreeNode(preorder[sp]);
	TreeNode* root = new TreeNode(preorder[sp]);
	int lsize;
	for (lsize = 0; lsize < (ei - si); lsize ++)
	{
		if (root->val == inorder[si + lsize]) break;
	}

	root->left = buildTree(preorder, inorder, sp + 1, sp + lsize, si, si + lsize);
	root->right = buildTree(preorder, inorder, sp + lsize + 1, ep, si + lsize + 1, ei);
	return root;
}

void printTreePreorder(TreeNode* root)
{
	if (root == nullptr) return;
	printf("%d ", root->val);
	printTreePreorder(root->left);
	printTreePreorder(root->right);
}

void printTreeInorder(TreeNode* root)
{
	if (root == nullptr) return;
	printTreeInorder(root->left);
	printf("%d ", root->val);
	printTreeInorder(root->right);
}

void t6()
{
	int parr1[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int iarr1[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int parr2[] = { 1, 2, 4 };
	int iarr2[] = { 2, 1, 4 };

	TreeNode* root = buildTree(parr1, iarr1, 0, 7, 0, 7);
	//TreeNode* root = buildTree(parr2, iarr2, 0, 2, 0, 2);
	printTreePreorder(root);
	printf("\n");
	printTreeInorder(root);
	printf("\n");
}

#endif
