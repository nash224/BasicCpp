// 39_DefaultTemplateArg.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 함수의 디폴트 인자처럼 템플릿도 디폴트 템플릿을 선언할 수 있다.
template <typename DataType, int num = 5>
DataType add_num(DataType _t)
{
	return _t + num;
}

template<typename DataType>
struct Compare
{
	bool operator()(const DataType& _Left, const DataType& _Right) const
	{
		return _Left < _Right;
	}
};

template<typename DataType, typename Comp = Compare<DataType>>
DataType Min(DataType a, DataType b)
{
	Comp comp;
	if (comp(a, b))
	{
		return a;
	}

	return b;
}

int main() 
{

	int a = 3;
	int b = 5;

	std::cout << "Min " << a << " , " << b << " :: " << Min(a, b) << std::endl;
	std::string s1 = "abc", s2 = "def";
	std::cout << "Min " << s1 << " , " << s2 << " :: " << Min(s1, s2) << std::endl;

	return 0;

	{
		int x = 3;
		std::cout << "x : " << add_num(x) << std::endl;
	}
}