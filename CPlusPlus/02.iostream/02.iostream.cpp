// 02.iostream.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// iostream은 출력할 데이터를 콘솔화면이나 표준 출력 장치로 띄운다.
#include <iostream>
#include <string>
#include <string_view>

int main()
{
    bool isvalue = false;
    int iValue = 3;
    float fValue = 3.23334f;
    double dValue = 3.22222186865;

    std::string Text = "Hello,";
    const char* cText = "World";
    char TextArr[6] = "World";


    std::cout << "Hello World!\n";
    std::cout << isvalue << std::endl;
    std::cout << iValue << std::endl;
    std::cout << fValue << std::endl;
    std::cout << dValue << std::endl;
    std::cout << Text << std::endl;
    std::cout << cText << std::endl;
    // 반드시 문자열이 아니더라도 출력된다.



    std::cout << cText << "\n" << cText << std::endl;
    // \n을 이스케이프 시퀀스라고 하고 이 문자열을 자유롭게 이용할 수 있다.


    if (cText == Text)
    {
        std::cout << "cText == Text" << std::endl;
        // 출력 안됨
        // 다르다는걸 알수있다.
    }

    if (false == Text.empty())
    {
        std::cout << "false == Text.empty()" << std::endl;
        // 출력됨
        // empty가 아니라면 출력되게 했는데 글자가 채워져있다.
    }


    std::string EmptyString = "";

    if (EmptyString.empty())
    {
        std::cout << "EmptyString.empty()" << std::endl;
        // 출력됨
    }

    std::string_view SvText = cText;


    if (SvText.empty())
    {
        std::cout << "SvText.empty()" << std::endl;
        // false 값이 있어서 empty가 아니다.
    }


    SvText = EmptyString;

    if (SvText.empty())
    {
        std::cout << "svTextisEmpty" << std::endl;
        // true 
    }

    char InputArr[256] = {};

    std::cin >> InputArr;
    // 스트림은 사용자 입력을 받을때 사용할 수 있다.
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
