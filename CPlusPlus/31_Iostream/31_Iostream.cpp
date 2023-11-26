// 31_Iostream.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 모든 입출력 클래스는 ios_base에 기반된다.
// ios_base : 입출력 형식 데이터를 처리
//          => 실수를 출력할 때 정밀도를 어떻게 처리할지, 정수형을 출력할때 10진수 또는 16진수로 출력할지
// 
// ios : 스트림 버퍼를 초기화함
//      => 스트림 버퍼란, 데이터를 내보내거나 받아들이기전 임시로 저장하는 곳 
//      스트림 버퍼는 왜 사용하는가? => 하나씩 읽으면 속도가 느려서 한꺼번에 불러와서 바로 읽게 준비해줌
//                                 => 저장된 바이트크기를 다 읽으면 다시 바이트 덩어리를 한꺼번에 불러옴

// istream : 입력을 수행함

// streambuf : 가장 기본적인 스트림 제어 담당
// 스트림 : 문자의 순차적인 나열
//          - 스트림 상태를 나타내기 위한 3개의 포인터를 가지고 있다.
//          - 시작 포인터, 끝 포인터, 다음 문자 포인터
//      - 입력버퍼 : get area
//      - 출력버퍼 : put area

int main()
{
    {
        std::string s;
        std::cin >> s;

        // rdbuf : streambuf 객체를 가리키는 포인터를 리턴
        // snextc : 한칸 전진하고 다음 해당하는 문자를 엿본다.
        char peek = std::cin.rdbuf()->snextc();
        if (std::cin.fail()) std::cout << "Failed";
        std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
        std::cin >> s;
        std::cout << "다시 읽으면 : " << s << std::endl;
    }

    return 0;

    int t;
    while (true) 
    {
        // 조작자 : hex와 같이 스트림을 조작해 출력 방식을 바꿔주는 것
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
        std::cin >> t;
        // endl에는 버퍼에 데이터가 얼마나 담겨있던 (flush) 버퍼를 모두 빼주는 함수가 있다.
        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) 
        {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();  // 플래그들을 초기화 하고
            // std::cin.ignore(100,'n');//개행문자가 나올 때까지
            // 무시한다
        }
        if (t == 0) break;
    }


    return 0;

    {
        int t;
        while (true) {
            std::cin >> t;
            std::cout << "입력 :: " << t << std::endl;

            // failbit 또는 badbit가 true가 나온다면 fail에서 true를 반환해준다.
            if (std::cin.fail()) 
            {
                std::cout << "제대로 입력해주세요" << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            if (t == 1) break;
        }
    }


    return 0;

    {
        int t;
        std::cin >> t;
        std::cout << "fail 비트가 켜진 상태이므로, 입력받지 않는다" << std::endl;
        std::string s;
        std::cin >> s;
    }

    return 0;

    {
        int t;
        while (true)
        {
            std::cin >> t;
            std::cout << "입력 :: " << t << std::endl;
            // 문자열을 입력하면 타입은 다르지만 ios에서 형변환되어 무한루프에 걸리지 않게 된다.
            // ios >> void* >> bool
            // void* 가 Null이면 bool로 형변환시 0으로 됨
            if (t == 0) break;
        }
    }
}
