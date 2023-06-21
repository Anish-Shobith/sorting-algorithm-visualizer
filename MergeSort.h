#ifndef SORT_VISUALIZER_MERGESORT_H_
#define SORT_VISUALIZER_MERGESORT_H_

#include <vector>

/**
 * @class MergeSort
 * @brief MergeSort class is used to sort an array using merge sort algorithm.
 * @param none
 * @return none
 */
class MergeSort
{
public:
	MergeSort();
	/**
	 * @name tick
	 * @details Sorts an array using merge sort algorithm.
	 * @param arr array to sort
	 * @param i current iteration
	 * @param operation_counter number of swap operation done
	 * @return true if sorting is done
	 * @return false if sorting is not done
	 */
	bool tick(std::vector<int> &arr, int &i, int &operation_counter);
	/**
	 * @name rebuild
	 * @details Rebuilds an array using merge sort algorithm.
	 * @param arr array to sort
	 * @return none
	 */
	void rebuild();

private:
	int BlockSizeIterator;
	int BlockIterator;
	int LeftBlockIterator;
	int RightBlockIterator;
	int MergeIterator;
	int LeftBorder;
	int MidBorder;
	int RightBorder;
	std::vector<int> SortedBlock;
};
#endif // SORT_VISUALIZER_MERGESORT_H_
