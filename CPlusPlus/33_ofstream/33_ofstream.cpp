// 33_ofstream.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


class Human 
{
    std::string Name;
    int Age;

public:
    Human(const std::string& name, int Age) 
        : Name(Name), Age(Age) 
    {

    }

    std::string GetInfo() 
    {
        return "Name :: " + Name + " / Age :: " + std::to_string(Age);
    }

    friend std::ofstream& operator<<(std::ofstream& _o, Human& _h);
};

std::ofstream& operator<<(std::ofstream& o, Human& h) 
{
    o << h.GetInfo();
    return o;
}


double to_number(std::string s) 
{
    // 문자열 타입을 지정 타입으로 변환해주는 클래스
    std::istringstream ss(s);
    double x;

    ss >> x;
    return x;
}

int main()
{

    to_number("5");

    return 0;
    {
        std::ofstream out("test.txt");

        Human h("이재범", 60);
        out << h << std::endl;
    }


    return 0;

    {
        // app 파일의 내용을 존중한다
        // ate 파일의 내용을 지우고 추가한다
        std::ofstream out("test.txt", std::ios::app);
        std::ofstream out2("test2.txt", std::ios::ate);

        out.seekp(3, std::ios::beg);
        out2.seekp(3, std::ios::beg);

        out << "추가";
        out2 << "추가";
    }

    return 0;

    {
        std::ofstream out("test.txt", std::ios::app);

        std::string s;
        if (out.is_open()) 
        {
            out << "true == true";
        }

        return 0;
    }


    return 0;

    {
        std::ofstream out("float2.txt");

        std::string s;
        if (out.is_open()) {
            out << "\n float2 is a float * 2";
        }
    }

    return 0;
}