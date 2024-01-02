#pragma once
#include <iostream>

#include "catchJump.h"
#include "try_catch.h"



int main()
{
	std::cout << "0 : ThrowTest 스택 이동 " << std::endl;
	std::cout << "1 : CatchJump 스택 이동" << std::endl;


	int SelectFunc = 0;
	std::cin >> SelectFunc;
	switch (SelectFunc)
	{
	case 0:
		ThrowTest();
		break;
	case 1:
		CatchJump();
		break;
	default:
		break;
	}


	
}

