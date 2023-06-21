#ifndef SORT_VISUALIZER_HEAPSORT_H_
#define SORT_VISUALIZER_HEAPSORT_H_

#include <algorithm>
#include <vector>

class HeapSort
{
public:
	HeapSort();
	HeapSort(int arr_size);
	bool tick(std::vector <int> &arr, int &i, int &n, int &operation_counter);
	void rebuild(int arr_size);

private:
	int start;
	int root;
};
#endif  // SORT_VISUALIZER_HEAPSORT_H_