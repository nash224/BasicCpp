#pragma once


#include <00_Leak/LeakCheck.h>
#include <string>

// 디폴트 인자 : 인자의 기본 값을 지정하는 것

#include <string>

// 설명 :
class MyVector
{
public:
	// constrcuter destructer
	MyVector(int n = 1);
	~MyVector();

	// delete Function
	MyVector(const MyVector& _Other) = delete;
	MyVector(MyVector&& _Other) noexcept = delete;
	MyVector& operator=(const MyVector& _Other) = delete;
	MyVector& operator=(MyVector&& _Other) noexcept = delete;

	

	void push_back(const char _s);

	size_t size() const
	{
		return static_cast<size_t>(Size);
	}

	size_t Buffer() const
	{
		return static_cast<size_t>(Capacity);
	}

	char operator[](int i)
	{
		if (Size <= i)
		{
			MsgBoxAssert("Nullptr");
			return char();
		}

		return Data[i];
	}

	void remove(int _i);

protected:

private:
	char* Data;
	unsigned int Capacity;
	unsigned int Size;


};

