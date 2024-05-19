// 60_Functional.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

struct AddCall
{
	void operator()(int _a, int _b)
	{
		std::cout << _a + _b << std::endl;
	}
};

int main()
{
	AddCall(4, 5);

    std::cout << "Hello World!\n";
}
