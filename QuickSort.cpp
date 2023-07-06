#include "QuickSort.h"

QuickSort::QuickSort()
{
	this->l=0;
	this->h=0;
	std::vector <int> stack;
	this->top=0;
	this->j=0;
	this->t=0;
	this->p=0;
}
QuickSort::QuickSort(std::vector <int> arr)
{
	this->l = 0;
	this->h = arr.size() - 1;
	this->stack = std::vector <int>(h - l + 1);
	this->top = -1;
	this->t = arr[h];
	this->p = (l - 1);
	this->j = l;
}

/**
 * Sorts the given vector using the QuickSort algorithm.
 *
 * @param arr the vector to be sorted
 * @param i the current index in the vector
 * @param operation_counter the counter to keep track of operations
 *
 * @return true if the sorting is successful, false otherwise
 *
 * @throws None
 */
bool QuickSort::tick(std::vector<int>& arr, int& i, int& operation_counter)
{
    while (true) {
        if (j <= h - 1) {
            if (arr[j] <= t) {
                std::swap(arr[++p], arr[j]);
                operation_counter++;
            }
            j++;
            i = j;
            return true;
        }

        if (j > h - 1) {
            std::swap(arr[p + 1], arr[h]);
            i = p + 1;
            operation_counter++;
            p++;

            if (p - 1 > l) {
                stack[++top] = l;
                stack[++top] = p - 1;
            }
            if (p + 1 < h) {
                stack[++top] = p + 1;
                stack[++top] = h;
            }
            if (top < 1)
                return true;

            h = stack[top--];
            l = stack[top--];
            t = arr[h];
            p = l - 1;
            j = l;
        }
    }
}

/**
 * Rebuilds the QuickSort object using the given array.
 *
 * @param arr the array to rebuild the QuickSort object with
 *
 * @throws None
 */
void QuickSort::rebuild(std::vector<int> arr)
{
    this->stack.clear();
    this->l = 0;
    this->h = arr.size() - 1;
    this->stack.resize(h - l + 1);
    this->top = -1;
    this->t = arr[h];
    this->p = (l - 1);
    this->j = l;
}
