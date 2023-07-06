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

/**
 * Implements the tick function for the HeapSort class.
 *
 * @param arr The input vector of integers to be sorted.
 * @param i The current index of the array being sorted.
 * @param n The size of the array being sorted.
 * @param operation_counter The counter for tracking the number of operations performed.
 *
 * @return Returns true if the tick operation is successful, otherwise false.
 *
 * @throws None.
 */
bool HeapSort::tick(std::vector<int>& arr, int& i, int& n, int& operation_counter)
{
    while (start >= 0)
    {
        while (2 * root + 1 <= arr.size() - 1)
        {
            int child = 2 * root + 1;
            int swap = root;

            if (child + 1 <= arr.size() - 1 && arr[swap] < arr[child + 1])
                swap = child + 1;

            if (arr[swap] < arr[child])
                swap = child;

            if (swap == root)
                break;

            std::swap(arr[root], arr[swap]);
            root = swap;
            operation_counter++;
            i = swap;
            return true;
        }
        start--;
        root = start;
    }

    if (start == -1)
    {
        this->root = 0;
        start = -2;
    }

    while (n > 0)
    {
        if (root == 0 || 2 * root + 1 > n)
        {
            std::swap(arr[n], arr[0]);
            operation_counter++;
            n--;
            this->root = 0;
        }

        while (2 * root + 1 <= n)
        {
            int child = 2 * root + 1;
            int swap = root;

            if (child + 1 <= n && arr[swap] < arr[child + 1])
                swap = child + 1;

            if (arr[swap] < arr[child])
                swap = child;

            if (swap == root)
            {
                root = 0;
                break;
            }

            std::swap(arr[root], arr[swap]);
            operation_counter++;
            root = swap;
            i = swap;
            return true;
        }
    }

    return false;
}

/**
 * Rebuilds the heap starting from the specified array size.
 *
 * @param arr_size the size of the array
 *
 * @throws ErrorType description of error
 */
void HeapSort::rebuild(int arr_size) {
    this->start = (arr_size - 2) >> 1;
    this->root = this->start;
}
