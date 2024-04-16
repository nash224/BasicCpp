#include "Heap.h"

#include <iostream>

void Heap::AllocateInt(int _count)
{
	int* Address = new int[_count];
	*Address = 1;
	std::cout << Address[0] << std::endl;
	delete[] Address;
}
