#ifndef SORT_VISUALIZER_SORT_H_
#define SORT_VISUALIZER_SORT_H_

#include <cstdlib>

#include <algorithm>
#include <vector>

#include <GL/glut.h>

#include "main.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"

extern int width, height;

/**
 * @class Sort
 * @brief Sort class is used to create an array of random numbers and sort it using one of the sorting algorithms.
 * @param size size of array
 * @param max_value max value of array element
 * @param xcoord bottom left x coordinate of array
 * @param ycoord bottom left y coordinate of array
 * @param xscale size scale of array
 * @param yscale size scale of array
 * @return none
 */
class Sort
{
public:
	Sort(unsigned size, unsigned max_value, int xcoord, int ycoord, float xscale, float yscale);

	void reshuffleArray();
	bool tick(SortingAlg alg);

	void drawArray();
	int getOperationCounter();
	int getArraySize();
	float getProgressPercentage();

private:
	std::vector<int> arr;
	int arr_size;			// initial size of array
	int max_value;			// max value of array element
	int x, y;				// drawArray bottom left coordinates
	float x_scale, y_scale; // size scale
	int n;					// size of subarray
	int i;					// current iteration
	int operation_counter;	// number of swap operation done

	BubbleSort bubble;
	MergeSort merge;
	HeapSort heap;
	QuickSort quick;
};
#endif // SORT_VISUALIZER_SORT_H_
