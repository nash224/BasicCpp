#include <bits/stdc++.h>
#include "RotLeft.h"
#include <list>

std::vector<int> RotLeft::rotLeft(std::vector<int> a, int d)
{
	std::vector<int> Result;
	std::list<int> Array;

	Result.reserve(a.size());

	for (int i = 0; i < a.size(); i++)
	{
		Array.push_back(a.at(i));
	}

	for (int i = 0; i < d; i++)
	{
		int PopInt = Array.front();
		Array.pop_front();
		Array.push_back(PopInt);
	}

	for (int iNum : Array)
	{
		Result.push_back(iNum);
	}

	return Result;
}
