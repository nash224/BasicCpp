#include <iostream>
#include <string>

class Base 
{
	std::string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	virtual void incorrect() { std::cout << "기반 클래스 " << std::endl; }
};
class Derived : public Base 
{
	std::string s;

public:
	Derived() : Base(), s("파생") {}

	// virtual로 선언된 함수를 자식에서 암시적으로 재정의 하면 그것도 override가 된다.
	// 하지만 상수함수와 일반함수가 이름이 같아도 엄연히 다른 함수이다.
	/*void incorrect() const { std::cout << "파생 클래스 " << std::endl; }*/
	void incorrect() override { std::cout << "파생 클래스 " << std::endl; }
};


int main()
{
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	std::cout << " == 실제 객체는 Base == " << std::endl;
	p_p->incorrect();

	std::cout << " == 실제 객체는 Derived == " << std::endl;
	p_c->incorrect();
	return 0;
}