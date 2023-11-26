// 28_VirtualTable.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 가상함수는 약간의 오버헤드를 동반한다.
//      => 호출 시간이 좀 더 오래걸린다.

class Parent 
{
public:
    Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
    virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }

    // 가삼 함수가 단 하나라도 있으면 클래스는 [가상 함수 테이블] 이라는 걸 만들어낸다.
    virtual void func1() {}
    virtual void func2() {}
};

class Child : public Parent 
{
public:
    Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
    ~Child() { std::cout << "Child 소멸자 호출" << std::endl; }


    virtual void func1() {}
    void func3() {}
};

// 상속을 하면 소멸자를 가상함수로 만들어야한다.

int main() {
    std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
    { 
        // 가상 함수는 일반함수와 다르게 추상테이블을 참조해서 함수를 호출한다.
        // 일반함수는 바로 함수를 호출한다.
        // 즉, 호출 시간이 조금 더 걸린다.
        Child c; 
        c.func3();
    }

    std::cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << std::endl;
    {
        // 자식의 소멸자가 호출되지 않음
        // 만약 자식에서 동적할당을 하고 있고 소멸자에 해제하는 코드를 넣었을때
        // 소멸자가 실행되지 않아 Memory Leak 이 남을 수 있음
        Parent* p = new Child();

        delete p;
    }


    std::cout << sizeof(Parent) << std::endl;
    
}
