// 13_Starcraft2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Marine {
    int hp;                // 마린 체력
    int coord_x, coord_y;  // 마린 위치
    int damage;            // 공격력
    bool is_dead;

public:
    Marine();              // 기본 생성자
    Marine(int x, int y);  // x, y 좌표에 마린 생성

    int attack();                       // 데미지를 리턴한다.
    void be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);            // 새로운 위치

    void show_status();  // 상태를 보여준다.
};

// 멤버 이니셜라이즈 리스트
// 이니셜라이즈 리스트 : 멤버를 생성자 호출 동시에 초기화
// ex) int a = 0;
// 생성 동시에 초기화
// 복사 생성자 호출
Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

// 원칙상 인자를 우선적으로 
Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

//Marine::Marine(int coord_x, int coord_y)
//    : coord_x(coord_x), coord_y(coord_y), hp(50), damage(5), is_dead(false) {}


// 인자에 인자를 넣으라는 형식
// 초기화가 않는다. => 우선권이 없다.
// ex) int a;
//      a = 20;
// // 생성 후 대입 => 디폴트 생성자 호출
//Marine::Marine(int coord_x, int coord_y)
//    : hp(50), damage(5), is_dead(false)
//{
//      // 생성 후 대입
//    coord_x = coord_x; 
//    coord_y = coord_y; 
//}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
        << std::endl;
    std::cout << " HP : " << hp << std::endl;
}


class InitClass
{
public:
    int a = 0;
    int b = 0;
    const int Ram;

    InitClass(int _Value, int _Init)
        : a(_Value) ,Ram(_Init)
    {
        std::cout << Ram << std::endl;
    }
};

int main() 
{

    InitClass ClassA(3, 6);

    return 0;
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();
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
