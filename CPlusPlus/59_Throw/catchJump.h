#pragma once
#include <iostream>
#include <stdexcept>


// 스택 풀기(stack unwinding)
//	=> catch로 점프하면서 스택 상에 정의된 객체들을 소멸시키는 과정

class Res
{
public:
	Res(int _Id) : Id(_Id) {}
	~Res() { std::cout << "리소스 해제 : " << Id << std::endl; }


private:
	int Id;
};


void func3()
{
	Res Resourcs(3);
	// 런타임 에러 터짐
	throw std::runtime_error("Exception form 3 \n");
}

void func2()
{
	Res Resourcs(2);
	func3();
	std::cout << "실행되나?" << std::endl;
}

void func1()
{
	Res Resourcs(1);
	func2();
	std::cout << "실행되나?" << std::endl;
}

void CatchJump()
{
	// 예외가 발생할만한 코드를 실행
	try
	{
		func1();
	}
	// Throw 함수스택에서 예외가 발생하면 스택에 있는 
	// 객체들은 소멸자를 호출되고 catch로 점프하게 됨
	catch (std::exception& E)
	{
		std::cout << "Excepth : " << E.what();
	}
}