// 12_Starcraft1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <00_Leak/LeakCheck.h>

class Marine {
    // 눈에 보이지는 않지만 private 접근지시자가 선언되어 있다.

    // 멤버변수이다.
    int hp;                // 마린 체력
    int coord_x, coord_y;  // 마린 위치
    int damage;            // 공격력
    bool is_dead;
    char* name;
    
    // 외부로 공개한다는 public 접근 지시사이다.
public:
    // 기본생성자
    Marine();              // 기본 생성자
    // 생성자인데 이거 선언하면 기본생성자를 자동으로 호출해주지 않게된다.
    // 누가? => 컴파일러가
    Marine(int x, int y);  // x, y 좌표에 마린 생성
    Marine(int x, int y, const char* marine_name);
    ~Marine();      // 소멸자는 인자를 단 하나도 가지지 않는다

    // 공격인데 내눈에는 공격으로 안보인다.
    int attack();                       // 데미지를 리턴한다.
    void be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);            // 새로운 위치

    void show_status();  // 상태를 보여준다.
};
// 외부에서 정의
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y)
{
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) 
{
    name = new char[strlen(marine_name) + 1];
    strcpy_s(name, strlen(marine_name) + 1, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::~Marine()
{
    if (name != NULL)
    {
        delete[] name;
        name = nullptr;
    }
}
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

class DesTest
{
public:
    int Test1;

public:
    DesTest();
    ~DesTest() = default;

};

DesTest::DesTest()
{
    std::cout << "생성자 호출" << std::endl;
}
//
//DesTest::~DesTest()
//{
//    std::cout << "소멸자 호출" << std::endl;
//}



class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(const Photon_Cannon& pc);     // 이 포토캐논의 정보로 새로운 포토캐논을 생성해라
                                                // const는 상수선언으로 인자를 고칠 수 없다
                                                // &는 이 주소를 참조하겠다라는 의미로 메모리를 아낄 수 있다. => 주소값은 8byte니까
    void show_status();                         // 인자로 받는 변수의 내용을 내부에서 바꾸지 않는다면 const 를 선언해 값의 변경을 막자
                                                // 컴파일러는 디폴트 복사생성자를 지원해주고 있기 때문에 굳이 선언해주지 않더라도 복사 생성자가 호출된다.

};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    std::cout << "복사 생성자 호출 !" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
        << std::endl;
    std::cout << " HP : " << hp << std::endl;
}


class CpyClass
{
public:
    int A;
    int B;
    int D;
    int C;
    int F;
    const char* Name;

public:
    CpyClass();
    CpyClass(const CpyClass& _Cpy);
    ~CpyClass();

};

CpyClass::CpyClass()
{
    Name = new char[5];
}

CpyClass::CpyClass(const CpyClass& _Cpy)
{
    Name = _Cpy.Name;
}

CpyClass::~CpyClass()
{
    delete[] Name;
}

int main()
{
    EngineLeak::LeakCheck();

    {
        CpyClass CpyClassA;
        // 안에서 얕은 복사가 일어났다. 그래서 소멸자에서 할당한 메모리를 지울때 
        // 할당하지 않은 메모리를 삭제해서 댕글링 포인터가 일어났다.
        CpyClass CpyClassB(CpyClassA);

        // 이런 문제를 해결하려면 어떻게 해야할까?
        // 메모리를 새로 할당해서 복사받으면 이런 문제를 해결할 수 있다.
    }



    return 0;

    {
        const char* StrName = "TTTEEEAS";

        char* CpyName = new char[strlen(StrName) + 1];
        strcpy_s(CpyName, strlen(StrName) + 1, StrName);

        std::cout << CpyName << std::endl;

        delete[] CpyName;
    }

    
    // 객체를 생성하고 지역을 벗어나면 소멸자를 호출한다.
    // 디폴트 소멸자가 존재한다.
    DesTest ClassA;

    


    // 메모리에서 

    return 0;

    Marine* Marines[100];
    
    // 동적할당한 객체는
    Marines[0] = new Marine();

    // 반드시 해제해주어야한다.
    delete Marines[0];




    return 0;
    // 호출자
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}