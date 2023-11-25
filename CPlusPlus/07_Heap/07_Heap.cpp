// 07_Heap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// Reference → 소유자가 아니고, 빌려왔으며, 비어 있지 않음을 보장할 때 사용

// 1. 인터페이스(함수 인터페이스를 지칭)에서는 Raw Pointer를 사용하자.


// heap memory Space -> 런타임 중에 내가 자유자재로 할당, 해제할 수 있는 공간
// Stack -> 내가 할당은 못하지만, 안정성이 어느정도 보장되어 있다.

// new -> 힙에 동적으로 할당한다.
// delete -> 동적할당한 힙을 해제한다(반환한다).
// None Heap delete -> 동적할당이 되지 않은걸 해제하면 치명적인 에러로 인식하여 터트린다.
// new 방치 -> 메모리 누수가 일어난다. 프로그램을 끝내기 전까지 계속 남게된다.


int main()
{

    // Leak 메모리 누수 검사
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);



    // 내가 힙 메모리에 4바이트를 사용하겠다.
    // 할당한 메모리 주소를 p주소 값에 집어넣곘다.
    int* p = new int;
    *p = 6;

    // Detected memory leaks!
    // Dumping objects ->
    // {154} normal block at 0x0000020E976A69A0, 4 bytes long.
    //     Data: < > 06 00 00 00
    //     Object dump complete.

    // 동적할당하고 메모리를 정리하지 않으면 터지지는 않지만 
    // 프로그램이 종료되기 전까지 영원히 메모리가 남는다.
    
    std::cout << *p << std::endl;

    // 사용을 다한 동적할당은 해제한다.
    delete p;
     
    // 하지만 한번 해제했는데 2번 해제할경우
    /*delete p;*/
    // 예외 발생(0x00007FF9B8DA030E(ucrtbased.dll), 07_Heap.exe) : 0xC0000005 : 0x000000000000810F 위치를 읽는 동안 액세스 위반이 발생했습니다..
    // nullptr를 참조했다며 터지게 된다.
    // 즉 delete는 동적할당을 한 메모리만 지울 수 있다.


    int arr_size;

    // size를 받고
    std::cout << "Input size : ";
    std::cin >> arr_size;

    // 입력받은 사이즈 배열만큼 동적할당한다.
    int* list = new int[arr_size];
    for (size_t i = 0; i < arr_size; i++)
    {
        std::cin >> list[i];
    }

    for (size_t i = 0; i < arr_size; i++)
    {
        std::cout << "Input Number : " << list[i] << std::endl;
    }
    
    // 힙에 할당한 배열을 제거하겠다.
    delete[] list;


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
