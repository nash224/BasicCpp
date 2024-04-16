#pragma once

/*
	스택 
	 - 로컬 변수는 현재 실행하고 있는 함수 스택에 위치
	 - 스택 프레임은 함수가 호출하면 생성됨
	 - 스택 프레임이 파괴시 로컬 변수도 파괴됨
	 - 스택 프레임은 스택 간 메모리 공간을 분리해줌
*/


namespace Stack
{
	// Stack bar
	void bar(int _Arg1, int _Arg2)
	{
		int a = _Arg1 + _Arg2;
	}

	// foo스택
	void foo()
	{
		int i = 5;
		int j = 7;

		bar(i,j); // 스택프레임 생성
	}
}