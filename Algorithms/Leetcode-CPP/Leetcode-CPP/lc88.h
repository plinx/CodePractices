#ifndef lc88_h
#define lc88_h

#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;

		while (0 <= i && 0 <= j)
		{
			if (nums1[i] < nums2[j]) nums1[k--] = nums2[j--];
			else nums1[k--] = nums1[i--];
		}

		while (0 <= j) nums1[k--] = nums2[j--];
	}
};

#endif