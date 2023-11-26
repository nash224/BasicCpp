#include <iostream>


// 순수 가상 함수가 단 하나라도 선언되어 있다면 그 클래스는 객체 생성이 불가능하다.
class Animal 
{
public:
	Animal() {}
	virtual ~Animal() {}

	// 무엇인지 정의되어 있지 않은 함수
	// 무조건 재정의 되어야 함
	// 이걸 순수 가상함수라고 함
	virtual void speak() = 0;
};

// 추상(abstract) 클래스 :  순수 가상함수를 단 하나라도 포함하고 있는 클래스
class Dog : public Animal 
{
public:
	Dog() : Animal() {}
	void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal 
{
public:
	Cat() : Animal() {}
	void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main() 
{
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	// 추상클래스를 가르키는 포인터는 문제가 없다.
	dog->speak();
	cat->speak();

	delete dog;
	delete cat;
}