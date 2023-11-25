// 16_mutable.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// const 멤버 함수에서 멤버변수의 값을 변경할 수 없다.
// 하지만 이런 const 멤버 함수에서 멤버 변수의 값을 변경을 허용하는 키워드가 있다.
// mutable 

#include <iostream>


class A {
    mutable int data_;

public:
    A(int data) : data_(data) {}

    void DoSomething(int x) const 
    {
        data_ = x;  // 값이 바꼇다.
    }

    void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};
//
//class Server {
//    // .... (생략) ....
//
//    Cache cache; // 캐쉬!
//
//    // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다.
//    User GetUserInfo(const int user_id) const 
//    {
//        // 1. 캐쉬에서 user_id 를 검색
//        Data user_data = cache.find(user_id);
//
//        // 2. 하지만 캐쉬에 데이터가 없다면 데이터베이스에 요청
//        if (!user_data) 
//        {
//            user_data = Database.find(user_id);
//
//            // 그 후 캐쉬에 user_data 등록
//            cache.update(user_id, user_data); // <-- 불가능
//        }
//
//        // 3. 리턴된 정보로 User 객체 생성
//        return User(user_data);
//    }
//};

int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();

    // const 멤버 함수 = 객체 내부에 영향을 주지 않는다.
        // => 읽기만 수행한다.

    // 그럼 애초에 상수 멤버 함수에서 굳이 멤버 변수에 mutable을 번거롭게 사용하는 이유가 뭐냐?
    // 사용자가 절때 값을 못바꾸게 하고 싶은데 함수 내부에서 업데이트를 돌려 값을 변경하고 싶을때가 있다.
    // 그래서 mutable을 선언해 그 업데이트 변수만 바꾸게 하는거다.
    // 
    // 서버에서는 유저의 데이터를 읽기 위해 데이터베이스에서 가져온다.
    // 하지만 요청을 받아 가져오는 것은 대게 느린 작업이다.
    // 그래서 서버들은 메모리에 캐쉬를 만들어 데이터베이스까지 가지 않아도 빠르게 가져올 수 있다.
    // 빠르게 정보를 가져오기 위해 메모리에 캐쉬를 만든다.
    // 하지만 캐쉬는 일부 정보만 가지고 있다.

}