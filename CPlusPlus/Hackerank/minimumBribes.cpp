#include "minimumBribes.h"
#include <iostream>

void MinimumBribes::SwapSticker(std::vector<int>& _Array, int _GiverNum, int _TakerNum)
{
	int GSticker = _Array[_GiverNum];
	int TSticker = _Array[_TakerNum];

	_Array[_GiverNum] = TSticker;
	_Array[_TakerNum] = GSticker;
}

int MinimumBribes::FindSticker(std::vector<int>& _q, int _Number)
{
	for (int i = 0; i < static_cast<int>(_q.size()); i++)
	{
		if (_q[i] == _Number)
		{
			return i;
		}
	}

	return -1;
}

void MinimumBribes::minimumBribes(std::vector<int> q)
{
	int Size = static_cast<int>(q.size());

	int TotalCount = 0;
	std::vector<int> SwapRecord;
	SwapRecord.resize(Size);
	for (int i = 0; i < Size; i++)
	{
		SwapRecord[i] = 0;
	}
	

	for (int i = 0; i < Size; i++)
	{
		int CheckSticker = i + 1;
		if (q.at(i) == i + 1)
		{
			continue;
		}

		int FindOrder = FindSticker(q, CheckSticker);
		SwapSticker(q, i, FindOrder);

		int Record = SwapRecord.at(i);
		Record += 1;
		SwapRecord.at(i) = Record;

		int SwapCount = FindOrder - i;

		TotalCount++;
	}

	int MaxCount = 0;

	for (int Number : SwapRecord)
	{
		MaxCount = std::max(MaxCount, Number);
	}

	if (MaxCount >= 3)
	{
		std::cout << "Too chaotic" << std::endl;
		return;
	}
	else
	{
		std::cout << TotalCount << std::endl;
	}
}