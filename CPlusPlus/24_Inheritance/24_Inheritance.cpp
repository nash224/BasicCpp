// 24_Inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// private : 자신을 제외하고 접근이 불가능하다. => 자식에서 부모 접근도 불가능하다.
// protected : 자신과 자식에서 접근이 가능하다. 하지만 외부로 공개는 불가능
// public : 자신 또는 외부로 접근 가능하다.


class Base 
{
protected:
    std::string parent_string;

public:
    Base() : parent_string("기반") { std::cout << "기반 클래스" << std::endl; }

    void what() { std::cout << parent_string << std::endl; }
};

class Derived : public Base 
{
    std::string child_string;

public:
    // 파생의 클래스 생성자는 디폴트로 기반 클래스의 생성자를 호출하게 되어있다.
    Derived() : Base(), child_string("파생")
    {
        std::cout << "파생 클래스" << std::endl;

        parent_string = "바꾸기";
    }


    // 다른 클래스에 정의되어 있기 때문에 다른 함수라고 취급한다.
    // 부모 클래스에 똑같은 이름이 정의되어 있고, 그걸 자식에게 물려주지만
    // 자식에서 재정의하면 자식의 함수가 호출된다.
    // 이걸 overriding이라고 한다.

    void what() { std::cout << parent_string << std::endl; }
};

int main()
{
    std::cout << " === 기반 클래스 생성 ===" << std::endl;
    Base p;
    p.what();

    std::cout << " === 파생 클래스 생성 ===" << std::endl;
    Derived c;
    c.Base::what();
}
