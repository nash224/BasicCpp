// 21_static_cast.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 캐스팅에는 크게 2가지가 있다.
// 명시적(explicit) : 내가 지정한 타입으로 변환함
// 암묵적(implicit) : 컴파일러가 알아서 변환함

class ParentClass
{
public:

private:
    int Hp = 7;
};

class ChildClass : ParentClass
{
private:
    int Att = 8;
};

int main()
{
    int iValue = 4;
    float fValue = 4.0f;
    static_cast<int>(fValue);
    // 형변환

    const int ciValue = 8;
    int* ptri = nullptr;
    ptri = const_cast<int*>(&ciValue);
    // 상수성을 없애는 형변환

    // dynamic_cast
    // 일반적으로 메모리가 줄어드는 건 문제가 되지 않는다.
    // 하지만 메모리가 추가 할당하고 형을 바꾸는건 위험을 동반한다.
    // 메모리가 추가로 생기면 그 자리의 값은 뭐가 들어 있을까?
    // 아마 쓰레기 값이 들어 있을것이다.
    // 그래서 그나마 안전하게 형변환해주는걸 컴파일러가 지원한다. 
    // dynamic_cast : 


    reinterpret_cast<__int64>(ptri);
    // 위험을 동반하고 서로 관련이 없는 자료형으로 변환을 하겠다.

    std::cout << "Hello World!\n";
}
