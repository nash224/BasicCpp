// 35_Template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "..\00_Leak\LeakCheck.h"

#include <iostream>
#include <string>

// 템플릿 인스턴스화 : 코드 템플릿에 인자 타입을 전달해서 코드를 생성하는 것
// 클래스에 대한 템플릿이라고 명시적으로 선언
// typename 에 class 가 와도 상관없음 
//  => 하지만 일반적으로 typename을 사용하길 권장
template <typename DataType>
class Vector {
    DataType* Data;
    int Buffer;
    int Size;

public:
    // 생성자
    Vector(int _Count = 1) 
        : Data(new DataType[_Count]), Buffer(_Count), Size(0) 
    {

    }

    ~Vector()
    {
        if (nullptr != Data)
        {
            delete[] Data;
        }
    }

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(DataType _Element) 
    {
        if (Buffer <= Size) {
            DataType* temp = new DataType[Buffer * 2];
            for (int i = 0; i < Size; i++) {
                temp[i] = Data[i];
            }
            delete[] Data;
            Data = temp;
            Buffer *= 2;
        }

        Data[Size] = _Element;
        Size++;
    }

    // 임의의 위치의 원소에 접근한다.
    DataType  operator[](int i) 
    {
        return Data[i]; 
    }

    // x 번째 위치한 원소를 제거한다.
    void remove(int _Order) {
        for (int i = _Order + 1; i < Size; i++)
        {
            Data[i - 1] = Data[i];
        }
        Size--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() 
    { 
        return Size; 
    }
};

int main() 
{
    EngineLeak::LeakCheck();

    // int 를 보관하는 벡터를 만든다.
    Vector<int> iVec;
    iVec.push_back(3);
    iVec.push_back(2);

    std::cout << "-------- int vector ----------" << std::endl;
    std::cout << "첫번째 원소 : " << iVec[0] << std::endl;
    std::cout << "두번째 원소 : " << iVec[1] << std::endl;

    Vector<std::string> StrVec;
    StrVec.push_back("hello");
    StrVec.push_back("world");
    std::cout << "-------- std::string vector -------" << std::endl;
    std::cout << "첫번째 원소 : " << StrVec[0] << std::endl;
    std::cout << "두번째 원소 : " << StrVec[1] << std::endl;
}