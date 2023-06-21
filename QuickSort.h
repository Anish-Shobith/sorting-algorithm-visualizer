#ifndef SORT_VISUALIZER_QUICKSORT_H_
#define SORT_VISUALIZER_QUICKSORT_H_

#include <vector>

/**
 * @class QuickSort
 * @brief QuickSort class is used to sort an array using quick sort algorithm.
 * @param none
 * @return none
 */
class QuickSort
{
public:
	QuickSort();
	/**
	 * @name QuickSort
	 * @details Constructor of QuickSort class.
	 * @param arr array to sort
	 * @return none
	 */
	QuickSort(std::vector<int> arr);
	/**
	 * @name tick
	 * @details Sorts an array using quick sort algorithm.
	 * @param arr array to sort
	 * @param i current iteration
	 * @param operation_counter number of swap operation done
	 * @return true if sorting is done
	 */
	bool tick(std::vector<int> &arr, int &i, int &operation_counter);
	/**
	 * @name rebuild
	 * @details Rebuilds an array using quick sort algorithm.
	 * @param arr array to sort
	 * @return none
	 */
	void rebuild(std::vector<int> arr);

private:
	int l;
	int h;
	std::vector<int> stack;
	int top;
	int j;
	int t;
	int p;
};
#endif // SORT_VISUALIZER_QUICKSORT_H_
