#include "HeapSort.h"

HeapSort::HeapSort()
{
	this->start = 0;
	this->root = 0;
}
HeapSort::HeapSort(int arr_size)
{
	this->start = (arr_size - 2) / 2;
	this->root = start;
}

bool HeapSort::tick(std::vector <int> &arr, int &i, int &n, int &operation_counter)
{
	while (start >= 0)
	{
		while (2 * root + 1 <= arr.size() - 1)
		{
			int child = 2 * root + 1;
			int swap = root;

			if (arr[swap] < arr[child]) swap = child;
			if ((child + 1 <= arr.size() - 1) && (arr[swap] < arr[child + 1])) swap = child + 1;
			if (swap == root) break;
			else
			{
				std::swap(arr[root], arr[swap]);
				root = swap;
				operation_counter++;
				i = swap;
				return true;
			}
		}
		start = start - 1;
		root = start;
	}

	//skip make max heap step when heap is already made
	if (start == -1)
	{
		this->root = 0;
		start = -2;
	}

	while (n > 0)
	{
		if (root == 0 || (2 * root + 1) > n)
		{
			std::swap(arr[n], arr[0]);
			operation_counter++;
			n = n - 1;
			this->root = 0;
		}

		while (2 * root + 1 <= n)
		{
			int child = 2 * root + 1;
			int swap = root;

			if (arr[swap] < arr[child]) swap = child;
			if ((child + 1 <= n) && (arr[swap] < arr[child + 1])) swap = child + 1;
			if (swap == root)
			{
				root = 0;
				break;
			}
			else
			{
				std::swap(arr[root], arr[swap]);
				operation_counter++;
				root = swap;
				i = swap;
				return true;
			}
		}
		return true;
	}
	return true;
}

void HeapSort::rebuild(int arr_size)
{
	this->start = (arr_size - 2) / 2;
	this->root = start;
}