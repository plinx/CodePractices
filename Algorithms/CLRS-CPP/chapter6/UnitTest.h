#ifndef UnitTest_h
#define UnitTest_h

//6.1-1
//max elements : 2^n - 1; min elements : 2^(n - 1) + 1

//6.1-4
//min element at A[length], the tail of heap

//6.1-5
//maybe

//6.1-6
/*
  {23, 17, 14, 6, 13, 10, 1, 5, 7, 12} is not a max-heap.
                23
         17      ,      14
    6  , 13      |      10  ,  1
  5, 7 | 12, nil | nil, nil | nil, nil
*/

//6.2-2
void e622()
{
	int max_arr[] = { 1, 5, 8, 6, 4, 3, 2, 7, 9 };
	int min_arr[] = { 8, 9, 1, 2, 3, 4, 5, 6, 7 };

	max_heapify(max_arr, 9, 0);
	min_heapify(min_arr, 9, 0);

	for (int i = 0; i < 8; i++)
		printf("%d, ", max_arr[i]);
	printf("%d\n", max_arr[8]);
	for (int i = 0; i < 8; i++)
		printf("%d, ", min_arr[i]);
	printf("%d\n", min_arr[8]);
}

//6.2-3
//A[i] is the max element, then max_heapify will do nothing

//6.2-4
//i > A.heap-size / 2, then left(i) > A.heap-size and right(i) > a.heap-size, max_heapify will do nothing

//6.2-5
void e625()
{
	int max_arr[] = { 1, 5, 8, 6, 4, 3, 2, 7, 9 };

	max_heapify_nonrecursive(max_arr, 9, 0);

	for (int i = 0; i < 8; i++)
		printf("%d, ", max_arr[i]);
	printf("%d\n", max_arr[8]);
}




#endif
