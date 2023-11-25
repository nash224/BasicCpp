// 09_Class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//
// 객체는 어떻게 만들어낼까?
// 바로 (클래스 == 설계도) 라는 녀석이다.
// 
//


#include <iostream>



// 어렵지도 않고 시간을 절약하기위해 코드를 긁어왔다.

class Animal {
    // Class는 기본적으로 눈에는 보이지 않지만 private 접근 지시사가 선언되어 있습니다.


    // 접근 지시사 : 외부에서 접근할 수 있냐 없냐.
    // private은 멤버 내에서 접근할 수 있습니다.
    // 다른의미로 외부나 자식에서 접근할 수 없다는 뜻입니다.
private:
    // 멤버 변수
    int food;
    int weight;

    // public은 외부에 공개한다는 것입니다.
public:
    // 멤버 함수
    void set_animal(int _food, int _weight) {
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc) {
        food += inc;
        weight += (inc / 3);
    }
    void view_stat() {
        std::cout << "이 동물의 food   : " << food << std::endl;
        std::cout << "이 동물의 weight : " << weight << std::endl;
    }
};  // 세미콜론 잊지 말자!


int main()
{

    Animal animal;  // Animal Class{설계도}의 animal 인스턴스{객체} 생성!
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();
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
