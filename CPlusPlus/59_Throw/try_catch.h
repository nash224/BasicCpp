#pragma once
#include <iostream>
#include <stdexcept>

// 예외란?
// 정상적인 상황에서 벗어난 예외적인 상황

// C에서는 예외 처리 방식이 존재하지 않는다.
//		=> 어떤 작업을 실행하고 결과값을 확인하는 방식으로 처리함

// throw : c++에서 예외적인 상황을 명시적으로 나타낼 수 있음
// throw를 호출한 함수에서 즉시 종료됨
// stack에 생성되었던 객체를 소멸시켜줌

template <typename T>
class MyVector
{
public:
	MyVector(size_t _size) : Size(_size)
	{
		Buffer = new T[Size];
		for (int i = 0; i < Size; i++)
		{
			Buffer[i] = 4;
		}
	}

	// 요청한 배열의 요소를 리턴하는 함수
	const T& at(size_t _Index) const
	{
		if (Size <= _Index)
		{
			// 예외로 전달하고 싶은 객체를 리턴해주면 됨
			throw std::out_of_range("인덱스가 Vector의 사이즈를 넘겼습니다.");
		}

		return Buffer[_Index];
	}

	~MyVector() { delete[] Buffer; }

private:
	T* Buffer;
	size_t Size;
};


void ThrowTest()
{
	std::cout << "MyVector에 접근할 원소를 입력하세요." << std::endl;

	MyVector<int> Vec(3);

	int Index, Data = 0;
	std::cin >> Index;

	// 예외가 발생할만한 코드가 실행됨
	try
	{
		// stack 에서 생성된 모든 객체의 소멸자를 호출되고, 가까운 catch 문으로 점프함
		Data = Vec.at(Index);
	}
	// throw 된 예외를 받는 부분
	catch (std::out_of_range& E)
	{
		// what 함수로 값을 확인이 가능
		std::cout << "예외 발생 !" << E.what() << std::endl;
	}

	std::cout << "읽은 데이터 : " << Data << std::endl;
}

