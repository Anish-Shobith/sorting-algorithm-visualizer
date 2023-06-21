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

bool QuickSort::tick(std::vector<int>& arr, int& i, int& operation_counter)
{
	if (j <= h - 1)
	{
		if (arr[j] <= t)
		{
			p++;
			std::swap(arr[p], arr[j]);
			operation_counter++;
		}
		j++;
		i = j;
		return true;
	}
	if (j > h - 1)
	{
		std::swap(arr[p + 1], arr[h]);
		i = p + 1;
		operation_counter++;
		p = p + 1;

		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - 1;
		}
		if (p + 1 < h)
		{
			stack[++top] = p + 1;
			stack[++top] = h;
		}
		if (top < 1) return true;

		h = stack[top--];
		l = stack[top--];
		t = arr[h];
		p = (l - 1);
		j = l;
		return true;
	}
	return true;
}

void QuickSort::rebuild(std::vector <int> arr)
{
	this->stack.clear();
	this->l = 0;
	this->h = arr.size() - 1;
	this->stack = std::vector <int>(h - l + 1);
	this->top = -1;
	this->t = arr[h];
	this->p = (l - 1);
	this->j = l;
}