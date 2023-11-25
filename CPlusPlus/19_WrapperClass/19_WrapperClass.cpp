// 19_WrapperClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Int
{
private:
    int data;

public:
    Int(int _data)
        : data(_data)
    {

    }

    Int(const Int& _i)
        : data(_i.data)
    {

    }


    operator int()
    {
        return data;
    }
};


int main()
{
    Int x = 3;
    int a = x + 4;

    x = a * 2 + x + 4;
    std::cout << x << std::endl;

    std::cout << "Hello World!\n";
}
