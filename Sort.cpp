#include "Sort.h"

Sort::Sort(unsigned size, unsigned maxvalue, int xcoord, int ycoord, float xscale, float yscale)
{
	this->arr_size = size;
	this->arr = std::vector<int>(arr_size);
	for (int i = 0; i < arr_size; i++)
	{
		this->arr[i] = rand() % maxvalue;
	}
	this->n = arr.size() - 1;
	this->max_value = maxvalue;
	this->x = xcoord;
	this->y = ycoord;
	this->x_scale = xscale;
	this->y_scale = yscale;
	this->i = 1;
	this->operation_counter = 0;

	BubbleSort bubble;
	MergeSort merge;
	HeapSort heap(this->arr_size);
	QuickSort quick(this->arr);
}

void Sort::reshuffleArray()
{
	for (int i = 0; i < arr_size; i++)
	{
		this->arr[i] = rand() % max_value;
	}

	this->n = arr_size - 1;
	this->operation_counter = 0;
	this->i = 1;

	merge.rebuild();
	heap.rebuild(this->arr_size);
	quick.rebuild(this->arr);
}

bool Sort::tick(SortingAlg alg)
{
	if (std::is_sorted(arr.begin(), arr.end()))
		return false;

	switch (alg)
	{
	case SortingAlg::BUBBLE:
		return bubble.tick(arr, i, n, operation_counter);
		break;
	case SortingAlg::MERGE:
		return merge.tick(arr, i, operation_counter);
		break;
	case SortingAlg::HEAP:
		return heap.tick(arr, i, n, operation_counter);
		break;
	case SortingAlg::QUICK:
		return quick.tick(arr, i, operation_counter);
		break;
	default:
		return true;
	}
	return true;
}

void Sort::drawArray()
{
	// Draw all array elements with green color
	glColor3f(0, 1, 0);
	for (unsigned j = 0; j < arr.size(); j++)
	{
		glRectf(
			this->x + (this->x_scale * j * 6),
			this->y,
			this->x + 3 + (this->x_scale * j * 6),
			this->y + this->y_scale * arr[j]);
	}

	// Draw current iteration with red color
	glColor3f(0.1, 0.5, 1);
	glRectf(
		this->x + (this->x_scale * this->i * 6),
		this->y,
		this->x + 3 + (this->x_scale * this->i * 6),
		this->y + this->y_scale * arr[this->i]);
}

int Sort::getOperationCounter()
{
	return this->operation_counter;
}

int Sort::getArraySize()
{
	return this->arr.size();
}