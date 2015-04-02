#include <iostream>
#include <vector>

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	void MergeSort(int low, int high, vector<Interval> &intervals)
	{
		if (high - low < 2)
		{
			if (intervals[low].start > intervals[high].start)
				swap(intervals[low], intervals[high]);
			return;
		}
		int mi = (low + high) >> 1;

		MergeSort(low, mi, intervals);
		MergeSort(mi, high, intervals);
		Merge(low, mi, high, intervals);
	}

	void Merge(int low, int mi, int high, vector<Interval> &intervals)
	{
		Interval* A = &intervals[low];
		int lb = mi - low;
		Interval* B = new Interval[lb];
		for (int i = 0; i < lb; B[i] = A[i++]);
		int lc = high - mi;
		Interval* C = &intervals[mi];

		for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc);)
		{
			if ((j < lb) && (!(k < lc) || (B[j].start <= C[k].start)))
			{
				A[i].start = B[j].start;
				A[i].end = B[j].end;
				i++;
				j++;
			}
			if ((k < lc) && (!(j < lb) || (C[k].start <= B[j].start)))
			{
				A[i].start = C[k].start;
				A[i].end = C[k].end;
				i++;
				k++;
			}
		}
	}

	vector<Interval> merge(vector<Interval> &intervals) {

		vector<Interval> vret;
		
		if (intervals.empty())
			return vret;
		
		MergeSort(0, intervals.size() - 1, intervals);
		for (auto &v : intervals)
		{
			cout << "[" << v.start << "," << v.end << "]" << " ";
		}

		vret.push_back(Interval(intervals[0].start, intervals[0].end));

		for (vector<Interval>::size_type i = 0; i < intervals.size(); i++)
		{
			if (intervals[i].start <= vret[vret.size() - 1].end)
			{
				if (intervals[i].end > vret[vret.size() - 1].end)
					vret[vret.size() - 1].end = intervals[i].end;
			}
			else
			{
				vret.push_back(Interval(intervals[i].start, intervals[i].end));
			}

		}

		return vret;
	}
};

int main()
{
	Solution lc;
	//vector<Interval> vin = { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
	vector<Interval> vin = { { 1, 4 }, { 3, 5 }, { 0, 2 } };
	vector<Interval> vout;
	
	//lc.bubbleSort(0, vin.size() - 1, vin);

	/*for (auto &v : vin)
	{
		cout << "[" << v.start << "," << v.end << "]" << " ";
	}*/

	vout = lc.merge(vin);
	cout << endl << "====" << endl;

	for (auto &v : vout)
	{
		cout << "[" << v.start << "," << v.end << "]" << " ";
	}
	cout << endl;

	return 0;
}

