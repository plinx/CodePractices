#ifndef lc103_h
#define lc103_h

#include <iostream>
#include <algorithm>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		if (root == NULL) return vector<vector<int>>();

		vector<vector<int>> result(1);
		queue<TreeNode*> queue;
		TreeNode* end = NULL;
		TreeNode* tail = root;

		int row = 0;
		queue.push(root);
		while (!queue.empty())
		{
			result[row].push_back(queue.front()->val);
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
				tail = end;
				if (1 < queue.size())
				{
					result.push_back(vector<int>());
					row++;
				}
			}
			queue.pop();
		}

		for (int i = 0; i < result.size(); i++)
			if (i % 2) reverse(result[i].begin(), result[i].end());

		return result;
	}

};

int lc103()
{
	vector<int> nodes = { 1, 2, 3, 4, 5, 6, NULL, 8};
	TreeNode* tree = buildTree_level(nodes);
	auto result = Solution().zigzagLevelOrder(tree);

	cout << "[" << endl;
	for (auto row : result)
	{
		cout << "[ ";
		for (auto r : row)
			cout << r << " ";
		cout << "]" << endl;
	}
	cout << "]" << endl;

	preoder_travel(tree); cout << endl;
	inorder_travel(tree); cout << endl;

	system("pause");
	return 0;
}

#endif