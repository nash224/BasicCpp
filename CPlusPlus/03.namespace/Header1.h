#pragma once
#include "Header2.h"

namespace header1
{
	// header1에 foo 함수가 있고 bar함수가 있다.
	int foo() 
	{
		return 1;
	}

	void bar()
	{
		// 네임스페이스에 자신의 함수를 호출하면 암묵적으로 자신의 함수를 호출한다.
		foo();

		// 명시적으로 header2의 함수를 호출한다.
		header2::foo();
	}
}