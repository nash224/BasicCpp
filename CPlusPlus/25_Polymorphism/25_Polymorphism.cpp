// 25_Polymorphism.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

// 상속은 C 언어에서 없던 구조체 사이의 관계를 표현할 수 있다.
// Manager은 Employee의 모든 기능을 포함한다.
// Manager는 Employee 다.
// 모든 상속관계는 'is a' 라고 표현한다.

// 상속관계의 도표에서 자식클래스가 부모클래스를 화살표로 가르킨다. 

// 특수화(구체화 : specialize) : 클래스가 파생될 수록 상세해진다.
// 
// 일반화(generialize) : 기반으로 올라갈 수록 일반화가 된다.

class Engine
{

};

class Brake
{

};

class Car 
{
private:
    Engine e;
    Brake b;
};


class Base {
    std::string s;

public:
    Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

    void what() { std::cout << s << std::endl; }
};


class Derived : public Base
{
    std::string s;

public:
    Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

    void what() { std::cout << s << std::endl; }
};


int main() 
{
    Base p;
    Derived c;

    std::cout << "=== 포인터 버전 ===" << std::endl;
    Base* p_c = &c;
    // 내가 파생이지만 기반으로 형변환되서 기반의 함수를 실행한다.
    // 이런 캐스팅을 [업캐스팅]이라고 한다.

    // 업캐스팅 : 자식의 포인터에서 부모의 포인터로 형변환하는 과정
    p_c->what();

    // 부모에서 자식으로 변환하는 건 부모의 메모리를 자식의 메모리로 인식한다는 건데
    // 있는 메모리를 줄이는건 안전한 캐스팅이지만
    // 없는 메모리를 늘리는건 위험한 캐스팅으로 컴파일러에서 함부로 다운 캐스팅을 하지말라고 막는다.
    /*Derived* Child = &p;*/

    Derived* p_p = dynamic_cast<Derived*>(p_c);

    return 0;
}


int main()
{
    std::cout << "Hello World!\n";
}