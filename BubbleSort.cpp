#include "BubbleSort.h"

BubbleSort::BubbleSort()
{

}

bool BubbleSort::tick(std::vector <int> &arr, int &i, int &n, int &operation_counter)
{
	bool swapped = false;
	while (i < n + 1)
	{
		if (arr[i - 1] > arr[i])
		{
			std::swap(arr[i - 1], arr[i]);
			swapped = true;
			operation_counter++;
			break;
		}
		i++;
	}
	if (swapped == false)
	{
		i = 1;
		n--;
		return true;
	}
	return true;
}