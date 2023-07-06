#include "BubbleSort.h"

BubbleSort::BubbleSort()
{

}

/**
 * Sorts an array using the Bubble Sort algorithm.
 *
 * @param arr the array to be sorted
 * @param i the current index of the array being compared
 * @param n the number of elements left to be sorted
 * @param operation_counter the counter for tracking the number of operations
 *
 * @return true indicating the sorting was completed
 *
 * @throws None
 */
bool BubbleSort::tick(std::vector<int>& arr, int& i, int& n, int& operation_counter) {
    bool swapped = false;
    while (i < n + 1) {
        if (arr[i - 1] > arr[i]) {
            std::swap(arr[i - 1], arr[i]);
            swapped = true;
            operation_counter++;
            break;
        }
        i++;
    }
    if (!swapped) {
        i = 1;
        n--;
    }
    return true;
}
