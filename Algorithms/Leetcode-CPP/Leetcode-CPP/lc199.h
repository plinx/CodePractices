#ifndef lc199_h
#define lc199_h

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree_level(vector<int> table)
{
	TreeNode* root = NULL;
	TreeNode* node = NULL;
	queue<TreeNode*> queue;
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i] != NULL)
			node = new TreeNode(table[i]);
		else
			node = NULL;
		if (!queue.empty())
		{
			if (i % 2)
			{
				queue.front()->left = node;
			}
			else
			{
				queue.front()->right = node;
				if (queue.front()->left != NULL) queue.push(queue.front()->left);
				if (queue.front()->right != NULL) queue.push(queue.front()->right);
				queue.pop();
			}
		}
		else
		{
			root = node;
			queue.push(node);
		}
	}

	return root;
}

void preoder_travel(TreeNode* root)
{
	if (root == NULL) return;
	cout << root->val << " ";
	preoder_travel(root->left);
	preoder_travel(root->right);
}

void inorder_travel(TreeNode* root)
{
	if (root == NULL) return;
	inorder_travel(root->left);
	cout << root->val << " ";
	inorder_travel(root->right);
}

class Solution
{
public:
	vector<int> rightSideView(TreeNode* root)
	{
		if (root == NULL) return vector<int>() ;

		vector<int> result;
		queue<TreeNode*> queue;
		TreeNode* end = NULL;
		TreeNode* tail = root;

		queue.push(root);
		while (!queue.empty())
		{
			if (queue.front()->left != NULL)
			{
				queue.push(queue.front()->left);
				end = queue.front()->left;
			}
			if (queue.front()->right != NULL)
			{
				queue.push(queue.front()->right);
				end = queue.front()->right;
			}
			if (tail == queue.front())
			{
				result.push_back(queue.front()->val);
				tail = end;
			}
			queue.pop();
		}
		return result;
	}

};

int lc199()
{
	vector<int> nodes = { 1, 2, 3, 4, 5, 6, NULL, 8 };
	TreeNode* tree = buildTree_level(nodes);
	vector<int> result = Solution().rightSideView(tree);
	for (auto r : result)
		cout << r << " ";
	cout << endl;

	preoder_travel(tree); cout << endl;
	inorder_travel(tree); cout << endl;

	system("pause");
	return 0;
}

#endif