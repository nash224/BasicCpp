#pragma once
#include <memory>
#include <iostream>

#include "Heap.h"
#include "Exception.h"

int main()
{
	try
	{
		DevideNumber(5.0, 0.0);
	}
	catch (const std::exception& _Msg)
	{
		std::cout << _Msg.what() << std::endl;
	}

	// Heap::AllocateInt(10);
};