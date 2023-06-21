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
	return true;
}

void MergeSort::rebuild()
{
	this->SortedBlock.clear();
	this->BlockSizeIterator = 1;
	this->BlockIterator = 0;
	this->LeftBlockIterator = 0;
	this->RightBlockIterator = 0;
	this->SortedBlock = std::vector<int>(RightBorder - LeftBorder);
	this->MergeIterator = 0;
}
