// 05_reference.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 받은 인자가 복사되었다.
void InputNuner(int _Number)
{
    _Number = 22222777;
}


// 함수에 들어오면 변수가 바껴나온다
void changeNumber(int* _Number)
{
    (*_Number) = 6;
}


void CopyAddressCheck(int _Number)
{
    std::cout << std::uint64_t(&_Number)  << std::endl;
}

void RefAddressCheck(int* _pNumber)
{
    std::cout << std::uint64_t(_pNumber) << std::endl;
}

template<typename Type>
void MyPrintf(Type& _value)
{
    std::cout << _value << std::endl;
}


int main()
{
    int number = 4;

    InputNuner(number);
    std::cout << number << std::endl;
    // 바뀌지 않았다.

    changeNumber(&number);
    std::cout << number << std::endl;
    // 바꼇다
    // 함수에 number의 주소값을 넣어 주소값이 가리키는 값을 바꿨다.
    

    std::cout << std::uint64_t(&number) << std::endl;
    CopyAddressCheck(number);
    // 다른 주소값

    std::cout << std::uint64_t(&number) << std::endl;
    RefAddressCheck(&number);
    // 같은 주소값

    // another_nubmer는 number를 참조하고 있다. 같은 주소를 사용하고 잇다
    // 즉 another_number 는 number의 또다른 이름이다라고 컴파일러에게 알려준다.
    int& another_number = number;

    // 레퍼런스는 반드시 누구의 이름인지를 명시해야한다. 아닐경우 컴파일러가 오류라고 알려준다
    /*int& p;*/
    // 1>C:\C\Cpp\05_reference\05_reference.cpp(59,11): error C2530: 'p': 참조를 초기화해야 합니다.


   
    // 레퍼런스는 한번 별명이 정해지면 다른 변수의 별명이 될 수 없다.
    int number2 = 76;

    // 밑에 의미는
    // 이미 정해진 a의 주소값인 another_number에 number2를 넣어라 라는 것이 됨으로
    // number = number2; 라는 식이 된다.
    
    another_number = number2;
    // 즉 number 에 76의 값이 들어온다.


    int number3 = 7;
    int* pnubmer3 = &number3;
    // pnumber3 주소에 number3의 주소를 담았는데

    int number4 = 4;
    pnubmer3 = &number4;
    // pumber3 주소에 number4의 주소를 넣었다
    // pumber3는 number4를 가리키고 있다.

    

    // c++부터는 레퍼런스를 사용하는 이유가 코드를 덜치기 위해서 만들어졌다.
    // 원래 Printf에서 글자를 출력하려면 printf("%d" ,&Name)을 넣어줬어야했는데 
    // 인자에서 레퍼런스로 받으면 굳이 주소값을 줄 필요가 없어졌기 떄문이다.
    // 함수 인자에서 
    MyPrintf(number4);



    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
