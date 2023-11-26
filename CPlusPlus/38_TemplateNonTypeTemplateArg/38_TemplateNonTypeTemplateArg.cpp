// 38_TemplateNonTypeTemplateArg.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>

template <typename DataType, int num>
DataType add_num(DataType _t)
{
	return _t + num;
}

// array는 크기를 지정해줘야한다. => 정적할당이기 때문
void PrintArray(const std::array<int, 5>& arr) 
{
	for (int i = 0; i < arr.size(); i++) 
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

template<typename ArrayType>
void PrintArray(const ArrayType& _Arr)
{
	for (int i = 0; i < _Arr.size(); i++)
	{
		std::cout << _Arr[i] << " ";
	}

	std::cout << std::endl;
}

int main() 
{
	// array는 동적이 아닌 스택에 할당된다.
	std::array<int, 5> Arr = { 1,2,3,4,5 };
	std::array<int, 8> Arr1 = { 1,2,3,4,5,5,6,7 };
	std::array<int, 13> Arr3 = { 1,2,3,4,5,4,3,5,67,84, 2};
	// {}는 유니폼 초기화라고 불린다.

	PrintArray(Arr);
	PrintArray(Arr1);
	PrintArray(Arr3);

	return 0;

	int x = 3;
	// 무조건 템플릿 꺽쇠를 통해 전달해줘야한다.
	// 만약 전달하지 않으면 컴파일러가 num 부분이 뭐냐며 에러를 낸다
	std::cout << "x : " << add_num<int, 5>(x) << std::endl;

}