#pragma once

#include <iostream>
#include <string>


/*
	decltype
	 - 표현식을 인자로 받아 타입을 알아냄
*/

auto foo()
{
	auto x = 35325;
	decltype(x) y = x;
	return y;
}

const std::string bar()
{
	return "HHPP";
}

int main()
{
	std::cout << foo() << std::endl;

	auto Msg = bar(); // const 삭제됨
	decltype(auto) Msg = bar(); // 리턴 타입 유지
};