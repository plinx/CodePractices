#ifndef lc226_h
#define lc226_h

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL || root->left == NULL && root->right == NULL) return root;

		TreeNode* tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);

		return root;
	}
};

int lc226()
{
	return 0;
}

#endif