#ifndef Heap_h
#define Heap_h

#include <memory>

template <typename E, typename Comp>
class Heap
{
private:
	E* _heaps;
	int _num;
	int _maxSize;

	void shiftDown(int pos)
	{
		while (!isLeaf(pos))
		{
			int prior = leafChild(pos);
			int right = rightChild(pos);
			if ((right < n) && Comp::prior(_heaps[right], _heaps[prior]))
				prior = right;
			if (Comp::prior(_heaps[pos], _heaps[prior])) return;
			std::swap(_heaps[pos], _heaps[prior]);
			pos = prior;
		}
	}

public:
	Heap(E* heaps, int num, int maxSize)
		: _heaps(heaps), _num(num), _maxSize(maxSize) { buildHeap(); }

	int size() const { return _num; }
	bool isLeaf(int pos) const { return (pos >= n / 2) && (pos < n); }
	int leftChild(int pos) const { return pos * 2 + 1; }
	int rightChild(int pos) const { return pos * 2 + 2; }
	int parent(int pos) const { return (pos - 1) / 2; }
	void buildHeap()
	{
		for (int i = (n / 2) - 1; i >= 0; i--)
			shiftDown(i);
	}

	void insert(const E& item)
	{
		UT_Assert(_num < _maxSize, "Heap is full.");
		int curr = _num++;
		_heaps[curr] = item;
		while ((curr != 0) && (Comp::prior(_heaps[curr], _heaps[parent(curr)])))
		{
			std::swap(_heaps[curr], _heaps[parent(curr)]);
			curr = parent(curr);
		}
	}

	E removefirst()
	{
		UT_Assert(_num > 0, "Heap is empty.");
		std::swap(_heaps[0], _heaps[--_num]);
		if (_num != 0) shiftDown(0);
		return _heaps[_num];
	}

	E remove(int pos)
	{
		UT_Assert((pos >= 0) && (pos < _num), "Bad position");
		if (pos == (n - 1))
		{
			_num--;
		}
		else
		{
			std::swap(_heaps[pos], _heaps[--_num]);
			while ((pos != 0) && Comp::prior(_heaps[pos], _heaps[parent(pos)]))
			{
				std::swap(_heaps[pos], _heaps[parent(pos)]);
				pos = parent(pos);
			}
			if (_num != 0) shiftDown(pos);
		}
		return _heaps[_num];
	}
};

#endif
