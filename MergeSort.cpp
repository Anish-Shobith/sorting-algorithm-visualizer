#include "MergeSort.h"

MergeSort::MergeSort()
{
	this->BlockSizeIterator = 1;
	this->BlockIterator = 0;
	this->LeftBlockIterator = 0;
	this->RightBlockIterator = 0;
	this->SortedBlock = std::vector<int>(RightBorder - LeftBorder);
	this->MergeIterator = 0;
}
/**
 * Sorts the given vector using the merge sort algorithm.
 *
 * @param arr the vector to be sorted
 * @param i the index of the last element sorted
 * @param operation_counter the number of operations performed
 *
 * @return true if an element was sorted, false otherwise
 *
 * @throws None
 */
bool MergeSort::tick(std::vector<int> &arr, int &i, int &operation_counter)
{
	while (BlockSizeIterator < arr.size())
	{
		while (BlockIterator < arr.size() - BlockSizeIterator)
		{
			LeftBorder = BlockIterator;
			MidBorder = BlockIterator + BlockSizeIterator;
			RightBorder = BlockIterator + 2 * BlockSizeIterator;
			RightBorder = (RightBorder < arr.size()) ? RightBorder : arr.size();
			SortedBlock.resize(RightBorder - LeftBorder);

			while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
			{
				if (arr[LeftBorder + LeftBlockIterator] < arr[MidBorder + RightBlockIterator])
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
					LeftBlockIterator += 1;

					i = LeftBorder + LeftBlockIterator;
					operation_counter++;
					return true;
				}
				else
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
					i = MidBorder + RightBlockIterator;
					operation_counter++;
					RightBlockIterator += 1;
					return true;
				}
			}
			while (LeftBorder + LeftBlockIterator < MidBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
				i = LeftBorder + LeftBlockIterator;
				operation_counter++;
				LeftBlockIterator += 1;
				return true;
			}
			while (MidBorder + RightBlockIterator < RightBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
				i = MidBorder + RightBlockIterator;
				operation_counter++;
				RightBlockIterator += 1;
				return true;
			}
			while (MergeIterator < LeftBlockIterator + RightBlockIterator)
			{
				arr[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
				i = LeftBorder + MergeIterator;
				operation_counter++;
				MergeIterator++;
				return true;
			}
			MergeIterator = 0;
			SortedBlock.clear();
			BlockIterator += 2 * BlockSizeIterator;
			LeftBlockIterator = 0;
			RightBlockIterator = 0;
		}
		BlockIterator = 0;
		BlockSizeIterator *= 2;
	}
	return false;
}

/**
 * Rebuilds the MergeSort object.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void MergeSort::rebuild()
{
    SortedBlock.clear();
    BlockSizeIterator = 1;
    BlockIterator = 0;
    LeftBlockIterator = 0;
    RightBlockIterator = 0;
    SortedBlock.resize(RightBorder - LeftBorder);
    MergeIterator = 0;
}
