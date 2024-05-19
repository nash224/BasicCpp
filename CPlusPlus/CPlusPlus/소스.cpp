#include <iostream>

template<typename T>
void Call()
{
	T A = 0;
}

constexpr int sqr(int n)
{
	return n * n;
}

consteval int A = sqr(10);
constexpr int B = sqr(10);

constexpr int Callconsteval()
{
	return A* A;
}

consteval int C = Callconsteval();

int main()
{
	Call<const int>();

	return 0;
}