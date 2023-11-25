// 18_friend.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A
{
private:
    void private_func();
    int private_vari;

    // 클래스 B와 친구야 private 지정자에 있는 멤버여도 접근하게 해줄게
    friend class B;

    // func 함수에게 멤버를 공유한다.
    friend void func();

};

void A::private_func()
{

}

class B
{
public:
    void b()
    {
        A a;
        a.private_vari = 5;
    }
};

void func()
{
    A a;
    a.private_func();
}


int main()
{
    std::cout << "Hello World!\n";
}