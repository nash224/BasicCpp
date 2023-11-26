// 40_VariadicTemplate.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 가변 길이 템플릿 : 템플릿을 사용해서 임의의 개수의 인자를 받는 방법

template <typename DataType>
void print(DataType _Arg)
{
	std::cout << _Arg << std::endl;
}

// ... 템플릿 파라미터 팩 : 0개 이상의 템플릿 인자
//	- 템플릿은 자료형 앞에
//	- 함수는 자료형 뒤에 옴 
// 가변 길이 템플릿은 재귀적으로 호출됨
// 타입이 3개인 인자를 받게되면 첫번째 인자가 무슨 함수에 호출될지 정해지고 
// 나머지 2개의 타입은 다시 가변 템플릿 인자로 들어감
// 그리고 타입이 2개인 인자를 받아서 첫번째 인자가 정해지고 다시들어감
// 마지막으로 인자가 1개가 남았을경우 우선순위로 인자 타입이 맞는 함수로 호출되고 재귀가 종료하게 됨
template <typename DataType, typename... Types>
void print(DataType _Arg, Types... _Args)
{
	std::cout << _Arg << ", ";
	print(_Args...);
}


int main()
{
	print(1, 3.1, "abc");
	print(1, 2, 3, 4, 5, 6, 7);
}