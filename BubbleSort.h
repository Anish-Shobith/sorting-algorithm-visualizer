#ifndef SORT_VISUALIZER_BUBBLESORT_H_
#define SORT_VISUALIZER_BUBBLESORT_H_

#include <vector>

class BubbleSort
{
public:
	BubbleSort();
	bool tick(std::vector <int> &arr, int &i, int &n, int &operation_counter);
};
#endif  // SORT_VISUALIZER_BUBBLESORT_H_
