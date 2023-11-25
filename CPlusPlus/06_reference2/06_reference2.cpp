// 06_reference2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int& OutputNumber()
{
    int a = 7;
    return a;
}

int& OutputRefPara(int& _Para)
{
    return _Para;
}




int main()
{
    // 레퍼런스에 리터럴을 집어 넣게되면 컴파일 에러를 일으킨다.
    // 이유는 레퍼런스에 상수를 짛어넣지 못하게 막았으니까
    /*int& Ref = 6;*/

    const int lNumber = 87;
    //int& Ref = lNumber;
    // 상수는 못넣는다.

    // 레퍼런스에 참조자 선언을 하면 리터럴도 참조할 수 있다.
    const int& Ref = lNumber;

    int a = 0;
    int b = 0;


    char cArr[7] = { 1,2,3,4,5,6};
    std::cout << &cArr[0] << std::endl;
    std::cout << cArr << std::endl;

    char element1 = *(cArr + 1);
    std::cout << element1 << std::endl;

    // 주소 값이 존재한다는건 메모리가 상에서 존재한다는건데
    // 레퍼런스는 메모리를 먹지 않는다./
    // 그럼 레퍼런스는 메모리 상에 존재할까?
    // 아니다. 
    // 배열을 잘 생각해보면 배열의 이름은 배열의 첫번째 주소값을 가르킨다.

    // 참조자에 배열
    /*int& refArr[2] = { a,b };*/


    // 배열들의 레퍼런스는 불가능하지 않다.
    int arr[3] = { 1, 2, 3 };
    int(&ref)[3] = arr;

    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    // 123이 출력됨


    // 함수내에서 선언된 int형 변수의 레퍼런스를 반환해주면
    // 컴파일가 에러는 안내지만 오류는 일으킨다.
    // 함수 내부에서 생선한 지역변수는 함수 지역이 끝났을때 사라지기 때문에 오류를 일으킨다.
    // 이런걸 댕글링포인터라고 하는데 참조해야할 변수가 사라져서 값이 치명적인 오류를 일으키게 된다.
    // 댕글링 레퍼런스
    /*int OutputResult = OutputNumber();*/
    //std::cout << OutputResult << std::endl;

    
    // 함수에서 레퍼런스를 반환하고 있지만 
    // 인자로 받은 레퍼런스를 그대로 리턴해주는데 함수가 다 끝나고 파괴되어도 
    // 받은 레퍼런스 인자의 주소값을 넘겨주기 떄문에 오류를 일으키지 않는다.
    int Inputint = 6464;
    int OutputRefResult = OutputRefPara(Inputint);

    std::cout << OutputRefResult << std::endl;



    return 0;


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
