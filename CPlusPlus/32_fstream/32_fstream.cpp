// 32_fstream.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>

// fstream : 파일 스트림

int main()
{
    {
        // 파일 읽기 준비
        std::ifstream in("test.txt");
        char buf[100];

        if (!in.is_open()) 
        {
            std::cout << "파일을 찾을 수 없습니다!" << std::endl;
            return 0;
        }

        // operator bool() 캐스팅 연산자가 정의되어 있어서 형변환이 가능하다.
        while (in) 
        {
            // 다음 개행이 나올때까지 읽음
            // 물론 3번째 인자로 끊어서 읽을 수도 있음
            // buffer를 100번까지 읽는다고 되어 있는데
            // 마지막에는 /0가 들어있어서
            // 실질적으로 99글자까지 읽음
            in.getline(buf, 100);
            std::cout << buf << std::endl;
        }
    }


    return 0;

    {
        std::ifstream in("Buffer.txt");
        std::string s;

        if (in.is_open()) 
        {
            // 위치 지정자를 파일 끝으로 옮긴다.
            in.seekg(0, std::ios::end);

            // 그리고 그 위치를 읽는다. (파일의 크기)
            int size = in.tellg();

            // 그 크기의 문자열을 할당한다.
            s.resize(size);

            // 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
            in.seekg(0, std::ios::beg);

            // 파일 전체 내용을 읽어서 문자열에 저장한다.
            in.read(&s[0], size);
            std::cout << s << std::endl;
        }
        else {
            std::cout << "파일을 찾을 수 없습니다!" << std::endl;
        }

    }

    return 0 ;

    {
        std::ifstream in("Buffer.txt", std::ios::binary);
        std::string s;

        int x;
        if (in.is_open()) 
        {
            // 리틀 엔디안 형식으로 읽힘
            // 높은 주소값에 높은 자리수
            // 
            // 두번째 인자는 읽을 바이트이다
            in.read(reinterpret_cast<char*>(&x), 4);
            // 리틀 엔디안 형식으로 읽힘
            // 높은 주소값에 높은 자리수

            std::cout << std::hex << x << std::endl;
        }
        else 
        {
            std::cout << "파일을 찾을 수 없습니다!" << std::endl;
        }
    }

    return 0;
    
    // 생성자에서 파일의 경로를 연동한다.
    std::ifstream in("Buffer.txt");
    std::string s;

    if (in.is_open()) 
    {
        in >> s;
        std::cout << "입력 받은 문자열 :: " << s << std::endl;
    }
    else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }
    return 0;
}