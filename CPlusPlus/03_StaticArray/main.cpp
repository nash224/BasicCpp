#pragma once
#include <iostream>
#include <string>
#include <array>

/*
  배열 : 같은 변수 타입의 나열

*/

void VoidArgFunc(void)
{
	// 인자를 받지 않는 함수는 void가 파라미터에 넘겨 받아진다.
}

auto AlternativeFunction(int _Count) -> int
{
	return _Count;
}

void Print(int _Count, const int* _Arr, const std::string& _Msg)
{
	if (false == _Msg.empty())
	{
		std::cout << _Msg << std::endl;
	}

	for (int i = 0; i < _Count; i++)
	{
		std::cout << _Arr[i] << std::endl;
	}
}

int main()
{
	const int Arrc = 5;

	int Arr1[Arrc] = { 0 };
	int Arr2[Arrc] = { 2 };
	int Arr3[] = { 2, 5, 6, 2 };

	std::array<int, Arrc> STLArr = { 5, 3, 2};

	Print(Arrc, Arr1, "Arr1");
	Print(Arrc, Arr2, "Arr2");
	Print(4, Arr3, "Auto Initialize Value by Compiler ");

	Print(static_cast<int>(STLArr.size()), STLArr.data(), "use STL Array");

	int ReturnValue = AlternativeFunction(5);
	int a = 0;
	
};