#ifndef lc23_h
#define lc23_h

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
	template <typename T>
	vector<T*> listqSort(vector<T*>& lists)
	{
		int left = 0, right = lists.size();
		int mid;
		while (left < right)
		{
			mid = partition(lists, left, right);
		}
	}
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.empty()) return NULL;
		vector<ListNode*> result;

		ListNode* tmp = NULL;
		for (int i = 0; i < (int)lists.size(); i++)
		{
			tmp = lists[i];
			while (tmp)
			{
				result.push_back(tmp);
				//cout << tmp->val << endl;
				tmp = tmp->next;
			}
		}

		//for (int i = 1; i < result.size(); i++)
		//	result[i - 1]->next = result[i];

		return result[0];
	}
};

int lc23()
{
	vector<ListNode*> listHead = {};
	vector<vector<int>> listin = { { 1, 3, 5 }, { 2, 4, 8, 9 }, { 3, 5, 7 } };

	ListNode* curr = NULL;
	for (int i = 0; i < (int)listin.size(); i++)
	{
		listHead.push_back(new ListNode(listin[i][0]));
		curr = listHead[i];
		for (int j = 1; j < (int)listin[i].size(); j++)
		{
			curr->next = new ListNode(listin[i][j]);
			curr = curr->next;
		}
	}

	auto result = Solution().mergeKLists(listHead);

	while (result)
	{
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;

	system("pause");
	return 0;
}

#endif