typedef int Rank;
#define DEFAULT_CAPACITY 5

template <typename T>
class Vector
{
public:
	Rank Size; int Capacity; T *Element;
	void copyFrom(T const *A, int low, int high);
	void expand();
	void shrink();
	//bool bubble(Rank low, Rank high);	// version A
	Rank bubble(Rank low, Rank high);	// version B
	Rank max(Rank low, Rank high);
	void bubbleSort(Rank low, Rank high);
	void selectSort(Rank low, Rank high);
	void merge(Rank low, Rank mi, Rank high);
	void mergeSort(Rank low, Rank high);
	Rank partition(Rank low, Rank high);
	void quickSort(Rank low, Rank high);
	void heapSort(Rank low, Rank high);

public:
	Vector(int c = DEFAULT_CAPACITY, Rank s = 0, T v = 0)
		: Capacity(c), Size(s)
	{
		Element = new T[Capacity];
		for (int i = 0; i < Size; i++)
		{
			Element[i] = v;
		}
	}

	Vector(T const *A, Rank n) { copyFrom(A, 0, n); }
	Vector(T const *A, Rank low, Rank high) { copyFrom(A, low, high); }
	Vector(Vector<T> const &V) { copyFrom(V.Element, 0, V.Size); }
	Vector(Vector<T> const &V, Rank low, Rank high) { copyFrom(V.Element, low, high); }
	~Vector() { delete[] Element; }

	bool empty() const{ return !Size; }
	int disordered() const;
	Rank find(T const &e) const { return find(e, 0, Size); }
	Rank find(T const &e, Rank low, Rank high) const;
	Rank search(T const &e) const
	{
		return (0 >= Size) ? -1 : search(e, 0, Size);
	}
	Rank search(T const &e, Rank low, Rank high) const;
	T &operator[](Rank r) const;
	Vector<T> &operator=(Vector<T> const&);
	bool &operator<(Vector<T> const&);
	bool &operator==(Vector<T> const&);
	bool &operator!=(Vector<T> const&);
	T remove(Rank r);
	int remove(Rank low, Rank high);
	Rank insert(Rank r, T const &e);
	Rank insert(T const &e) { return insert(Size, e); }
	void sort(Rank low, Rank high);
	void sort() { sort(0, Size); }
	void unsort(Rank low, Rank high);
	int deduplicate();
	int uniquify();
	void traverse(void(*)(T&));
	template <typename T> void traverse(T&);
	void print();
};


template <typename T>
void Vector<T>::copyFrom(T const *A, Rank low, Rank high)
{
	Capacity = 2 * (high - low);
	Element = new T[Capacity];
	Size = 0;
	while (low < high)
	{
		Element[Size++] = A[low++];
	}
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &V)
{
	if (Element)
		delete[] Element;

	copyFrom(V.Element, 0, V.Size);
	return *this;
}

template <typename T>
void Vector<T>::expand()
{
	if (Size < Capacity)
		return;

	if (Capacity < DEFAULT_CAPACITY)
		Capacity = DEFAULT_CAPACITY;

	T *oldE = Element;
	Element = new T[Capacity <<= 1];
	for (int i = 0; i < Size; i++)
		Element[i] = oldE[i];
	delete[] oldE;
}

template <typename T>
void Vector<T>::shrink()
{
	if (Capacity < DEFAULT_CAPACITY << 1)
		return;

	if (Size << 2 > Capacity)
		return;

	T *oldE = Element;
	Element = new T[Capacity >>= 1];
	for (int i = 0; i < Size; i++)
		Element[i] = oldE[i];
	delete[] oldE;
}

template <typename T>
T& Vector<T>::operator[](Rank r) const
{
	return Element[r];
}

template <typename T>
void permute(Vector<T> &V)
{
	for (int i = V.Size; i > 0; i--)
		std::swap(V[i - 1], V[rand() % i]);
}

template <typename T>
void Vector<T>::sort(Rank low, Rank high)
{
	mergeSort(low, high);
}

template <typename T>
void Vector<T>::unsort(Rank low, Rank high)
{
	T *V = Element + low;
	for (Rank i = high - low; i > 0; i--)
		std::swap(V[i - 1], V[rand() % i]);
}

template <typename T>
bool &Vector<T>::operator<(Vector<T> const &V)
{
	return Element < V.Element;
}

template <typename T>
bool &Vector<T>::operator==(Vector<T> const &V)
{
	return Element == V.Element;
}

template <typename T>
bool &Vector<T>::operator!=(Vector<T> const &V)
{
	return Element != V.Element;
}

template <typename T>
Rank Vector<T>::find(T const &e, Rank low, Rank high) const
{
	while ((low < high--) && (e != Element[high]));
	return high;
}

template <typename T>
Rank Vector<T>::insert(Rank r, T const &e)
{
	expand();
	for (Rank i = Size; i > r; i--)
		Element[i] = Element[i - 1];
	Element[r] = e;

	return r;
}

template <typename T>
int Vector<T>::remove(Rank low, Rank high)
{
	if (low == high)
		return 0;

	while (high < Size)
		Element[low++] = Element[high++];
	shrink();

	return high - low;
}

template <typename T>
T Vector<T>::remove(Rank r)
{
	T e = Element[r];
	remove(r, r + 1);
	return e;
}

template <typename T>
int Vector<T>::deduplicate()
{
	int oldSize = Size;
	Rank i = 1;
	while (i < Size)
		(find(Element[i], 0, i) < 0) ? i++ : remove(i);
	return oldSize - Size;
}

template <typename T> template <typename VST>
void Vector<T>::traverse(VST &visit)
{
	for (int i = 0; i < Size; i++)
		visit(Element[i]);
}

template <typename T> struct Increase
{
	virtual void operator() (T& e) { e++; }
};

template <typename T> void increase(Vector<T> &V)
{
	V.traverse(Increase<T>());
}

template <typename T> int Vector<T>::disordered() const
{
	int n = 0;
	for (int i = 1; i < Size; i++)
		n += (Element[i - 1] > Element[i]);
	return n;
}

// low efficiency uniquify
/*
template <typename T> int Vector<T>::uniquify()
{
	int oldSize = Size;
	int i = 0;
	while (i < Size - 1)
		(Element[i] == Element[i + 1]) ? remove(i + 1) : i++;

	return oldSize - Size;
}
*/

// high efficiency uniquify
template <typename T> int Vector<T>::uniquify()
{
	Rank i = 0, j = 0;
	while (++j < Size)
	{
		if (Element[i] != Element[j])
			Element[++i] = Element[j];
	}
	Size = ++i;
	shrink();

	return j - i;
}

template <typename T>
Rank Vector<T>::search(T const &e, Rank low, Rank high) const
{
	//return (rand() % 2) ? binSearch(e, low, high) : fibSeach(e, low, high);
	return binSearch(Element, e, low, high);
}

// binary search version A, O(1.5lgn)
/*
template <typename T>
static Rank binSearch(T *A, T const &e, Rank low, Rank high)
{
	while (low < high)
	{
		Rank mi = (low + high) >> 1;
		if (e < A[mi]) high = mi;
		else if (A[mi] < e) low = mi;
		else return mi;
	}
	return -1;
}
*/

// fibonacci search, O(1.44lgn)
/*
template <typename T>
static Rank fibSearch(T *A, T const &e, Rank low, Rank high)
{
	Fib fib(high - low);
	while (low < high)
	{
		while (high - low < fib.get()) fib.prev();
		Rank mi = low + fib.get() - 1;
		if (e < A[mi]) high = mi;
		else if (A[mi] < e) low = mi;
		else return mi;
	}
	return -1;
}
*/

// binary search version B
/*
template <typename T>
static Rank binSearch(T *A, T const &e, Rank low, Rank high)
{
	while (1 < high - low)
	{
		Rank mi = (low + high) >> 1;
		(e < A[mi]) ? high = mi : low = mi;
	}
	return (e == A[mi]) ? low : -1;
}
*/

// binary search version C
template <typename T>
static Rank binSearch(T *A, T const &e, Rank low, Rank high)
{
	while (low < high)
	{
		Rank mi = (low + high) >> 1;
		(e < A[mi]) ? high = mi : low = mi + 1;
	}
	return --low;
}


// Version A
/*
template <typename T>
void Vector<T>::bubbleSort(Rank low, Rank high)
{
	while (!bubble(low, high--));
}

template <typename T>
bool Vector<T>::bubble(Rank low, Rank high)
{
	bool sorted = true;
	while (++low < high)
	{
		if (Element[low - 1] > Element[low)
		{
			swap(Element[low - 1], Element[low]);
			sorted = false;
		}
	}
	return sorted;
}
*/

template <typename T>
void Vector<T>::bubbleSort(Rank low, Rank high)
{
	while (low < (high = bubble(low, high)));
}

template <typename T>
Rank Vector<T>::bubble(Rank low, Rank high)
{
	Rank last = low;
	while (++low < high)
	{
		if (Element[low - 1] > Element[low])
		{
			swap(Element[low - 1], Element[low]);
			last = low;
		}
	}
	return last;
}

template <typename T>
void Vector<T>::mergeSort(Rank low, Rank high)
{
	if (high - low < 2) return;
	int mi = (low + high) >> 1;
	mergeSort(low, mi);
	mergeSort(mi, high);
	merge(low, mi, high);
}

template <typename T>
void Vector<T>::merge(Rank low, Rank mi, Rank high)
{
	T* A = Element + low;	
	int lb = mi - low;
	T* B = new T[lb];
	for (Rank i = 0; i < lb; B[i] = A[i++]);
	int lc = high - mi;
	T* C = Element + mi;
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);)
	{
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))
			A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (C[k] < B[j])))
			A[i++] = C[k++];
	}
	delete[] B;
}

template <typename T>
void Vector<T>::print()
{
	for (Rank i = 0; i < Size; i++)
		cout << Element[i] << " ";
	cout << endl;
}


