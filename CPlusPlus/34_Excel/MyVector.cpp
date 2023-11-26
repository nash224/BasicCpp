#include "MyVector.h"


MyVector::MyVector(int n)
	: Data(new char[n]), Capacity(n), Size(0)
{

}

MyVector::~MyVector() 
{
	if (nullptr != Data)
	{
		delete[] Data;
		Data = nullptr;
	}
}

void MyVector::push_back(const char _s)
{
	if (Capacity <= Size)
	{
		char* Temp = new char[Capacity *= 2];

		for (int i = 0; i < Size; i++)
		{
			Temp[i] = Data[i];
		}

		delete[] Data;
		Data = Temp;

	}

	Data[Size] = _s;
	++Size;
}

void MyVector::remove(int _i) 
{
	for (int i = _i; i < Size; i++)
	{
		Data[i - 1] = Data[i];
	}

	--Size;
}
