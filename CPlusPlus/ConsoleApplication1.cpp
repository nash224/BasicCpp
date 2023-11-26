// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 주석 : 프로그래머를 위해 만들어졌다. => 컴파일러는 주석을 무시한다.

// 전처리기
// 이건 중복된 헤더파일을 한번만 인클루드 한다.
#pragma once 

#include <iostream>

// c++ 프로그램은 main이 있어야하고 시작점이다.
// 만약 진입점이 없는데 시작하면 컴파일 오류가 발생한다.

// argc : 프로그램이 실행될때 명령줄에서 넘겨진 인자 갯수  == argv[] 의 size
// argv : 프로그램의 메인함수에 넘겨진 문자 배열 => 첫번째는 실행경로이다.

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    std::cout << "argc : " << argc << std::endl;

    for (size_t i = 0; i < argc; i++)
    {
        std::cout << "argc : "  << argv[i] << std::endl;
    }

    /*Hello World!
    argc : 1
    argc : C : \C\Cpp\ConsoleApplication1\x64\Debug\ConsoleApplication1.exe*/

    // 인자의 첫번째 배열은 실행 경로가 있다.

    // 리턴상태를 알려준다.
    return 0;
}

// C++은 3단계에 걸쳐서 빌드되는데
// 1. 전처리 작업으로 메타 정보를 인식하여 자동으로 코드를 수정해주고
// 2. 컴파일러를 통해 소스 코드를 기계어로 변역한다.
// 3. 링크 작업으로 기계어로 된 여러 오브젝트 파일을 묶어서 실행파일을 만든다.


// 전처리문은 해당 헤더파일 코드를 가져와서 소스파일에 삽입할 수 있게한다.

// 전처리문의 이론은 그 헤더파일의 내용을 원하고자하는 소스에 파일을 삽입한다.
// => 다른 곳에서 정의된 함수를 사용하기 위해 헤더파일을 삽입한다.

// Define : KeyWord 에 Value 를 치환한다.
// 매크로를 정의하지만 부작용이 존재한다.