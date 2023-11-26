// 52_Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// 알고리즘 라이브러리 : 컨테이너의 반복자를 가지고 여러가지 편리한 작업을 수행하는 것
//      - 알고리즘으로 정의되어있는 함수들을 호출할때, 인자로 BeginIter와 Enditer을 받는다.
//      - 추가로 Predicate를 받는 서술자(특정한 조건)을 같이 받는 것도 있다.
//      - 이런 Predicate 함수는 bool을 리턴하는 함수객체로 전달한다.
// 
// 정렬 알고리즘 
//      - sort : 일반적인 정렬
//      - stable_sort : 원소간의 순서를 보존하는 정렬
//          - 원소의 크기가 같아 배열에 들어가는 순서는 랜덤일지라도 들어가는 순서는 보존한다
//          - sort 보다 느리다
// 
//      - partial_sort : 배열의 일부분만 정렬
// 
// 

template<typename Iter>
void Print(Iter _begin, Iter _end)
{
	while (_begin != _end)
	{
		std::cout << (*_begin) << std::endl;
		++_begin;
	}

	std::cout << std::endl;
}

template<typename DataType>
struct GreaterCompare
{
	bool operator()(const DataType& _Left, const DataType& _Right) const
	{
		return _Left > _Right;
	}
};

struct User
{
public:
	std::string Name;
	int Age;

	User(const std::string& _Name, int _Age)
		: Name(_Name), Age(_Age)
	{

	}

	bool operator<(const User& _U) const
	{
		return Age < _U.Age;
	}
};

std::ostream& operator<<(std::ostream& _O, const User& _U)
{
	_O << _U.Name << " , " << _U.Age;
	return _O;
}


int main()
{
	{

		std::vector<User> vec;
		for (int i = 0; i < 100; i++) 
		{
			std::string name;
			name.push_back('a' + i / 26);
			name.push_back('a' + i % 26);
			vec.push_back(User(name, static_cast<int>(rand() % 10)));
		}

		std::vector<User> vec2 = vec;

		std::cout << "정렬 전 ----" << std::endl;
		Print(vec.begin(), vec.end());

		std::sort(vec.begin(), vec.end());

		std::cout << "정렬 후 ----" << std::endl;
		Print(vec.begin(), vec.end());

		std::cout << "stable_sort 의 경우 ---" << std::endl;
		// 원소간의 삽입되어있는 순서를 보존하며 정렬
		std::stable_sort(vec2.begin(), vec2.end());
		Print(vec2.begin(), vec2.end());
	}


	return 0;

	{
		std::vector<int> vec;
		vec.reserve(16);
		vec.push_back(5);
		vec.push_back(3);
		vec.push_back(1);
		vec.push_back(6);
		vec.push_back(4);
		vec.push_back(7);
		vec.push_back(2);

		std::cout << "정렬 전 ----" << std::endl;
		Print(vec.begin(), vec.end());

		// 임시 접근 반복자만 가능하다 (RandomAccessIterator)
		// std::sort(vec.begin(), vec.end(), GreaterCompare<int>());

		// 처음부터 요소 3번째까지 작은 순으로 정렬하고 그 뒤는 랜덤
		// 시간 복잡도는 Nlog(M) : N = 전체 원소 갯수, M 정렬 후 남은 원소
		std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());

		std::cout << "정렬 후 ----" << std::endl;
		Print(vec.begin(), vec.end());

		// 양방향 반복자는 오류가 난다.
		/*std::list<int> List;
		std::sort(List.begin(), List.end());*/
	}
}
