// 15_string_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


// C에서는 기존에는 문자열 끝에 NUll을 붙임


#include <iostream>
#include "..\00_Leak\LeakCheck.h"



class MyString
{
private:
    char* string_content;
    int string_length;
    int memory_capacity;

public:
    MyString(char _c);
    MyString(const char* _str);
    MyString(const MyString& _str);

    ~MyString();

    int Size() const;

    void print() const;
    void println() const;


    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    int Buffer();
    void reserve(int size);

    char at(int i) const;

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    MyString& erase(int loc, int num);

    int find(int find_from, MyString& str) const;

    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;

    int compare(const MyString& str) const;
};

MyString::MyString(char c) 
{
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
    memory_capacity = 1;
}
MyString::MyString(const char* str) 
{
    string_length = static_cast<int>(strlen(str));
    memory_capacity = string_length;
    string_content = new char[string_length];
    
    for (int i = 0; i != string_length; i++)
    {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str)
{
    string_length = str.string_length;
    memory_capacity = string_length;
    for (int i = 0; i != string_length; i++)
    {
        string_content[i] = str.string_content[i];
    }
}
MyString::~MyString() { delete[] string_content; }

int MyString::Size() const 
{
    return string_length;
}

void MyString::print() const 
{
    for (int i = 0; i != string_length; i++) 
    {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) 
    {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}


MyString& MyString::assign(const MyString& str)
{
    if (str.string_length > memory_capacity) 
    {
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) 
    {
        string_content[i] = str.string_content[i];
    }


    string_length = str.string_length;

    return *this;
}
MyString& MyString::assign(const char* str)
{
    int str_length = static_cast<int>(strlen(str));
    if (str_length > memory_capacity) 
    {
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }

    for (int i = 0; i != str_length; i++) 
    {
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}

int MyString::Buffer() 
{
    return memory_capacity; 
}

void MyString::reserve(int size) 
{
    if (size > memory_capacity) 
    {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }

    // 만일 예약하려는 size 가 현재 capacity 보다 작다면
    // 아무것도 안해도 된다.
}

char MyString::at(int i) const
{
    if (i >= string_length || i < 0)
        return NULL;
    else
        return string_content[i];
}

MyString& MyString::insert(int loc, const MyString& str)
{
    if (loc < 0 || loc > string_length) 
    {
        return *this;
    }

    if (string_length + str.string_length > memory_capacity)
    {
        if (memory_capacity * 2 > string_length + str.string_length)
        {
            memory_capacity *= 2;
        }
        else
        {
            memory_capacity = string_length + str.string_length;
        }
    }

    if (string_length + str.string_length > memory_capacity)
    {
        memory_capacity = string_length + str.string_length;
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];
        int i;
        for (i = 0; i < loc; i++)
        {
            string_content[i] = prev_string_content[i];
        }

        for (int j = 0; j < str.string_length; j++)
        {
            string_content[i + j] = str.string_content[j];
        }

        for (; i < string_length; i++)
        {
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;
        string_length = string_length + str.string_length;
        return *this;
    }

    for (int i = string_length - 1; i >= loc; i--) 
    {
        string_content[i + str.string_length] = string_content[i];
    }

    for (int i = 0; i < str.string_length; i++)
    {
        string_content[i + loc] = str.string_content[i];
    }

    string_length = string_length + str.string_length;
    return *this;
}

MyString& MyString::insert(int loc, const char* str) 
{
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) 
{
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num)
{
    if (num < 0 || loc < 0 || loc > string_length) 
    {
        return *this;
    }

    for (int i = loc; i < string_length; i++)
    {
        string_content[i] = string_content[i + num];
    }

    string_length -= num;

    return *this;
}

int MyString::find(int find_from, MyString& str) const
{
    static constexpr const int NotFindValue = -1;

    if (str.string_length == 0)
    {
        return NotFindValue;
    }

    for (int i = find_from; i < string_length - str.string_length; i++)
    {
        for (int j = 0; j < str.string_length; j++)
        {
            if (string_content[i + j] != str.string_content[j])
            {
                break;
            }
            else
            {
                if (j == str.string_length - 1)
                {
                    return i;
                }
            }
        }
    }

    return NotFindValue;
}

int MyString::find(int find_from, const char* str) const
{
    MyString Temp(str);
    return find(find_from, Temp);
}

int MyString::find(int find_from, char c) const
{
    MyString Temp(c);
    return find(find_from, Temp);
}

int MyString::compare(const MyString& str) const 
{
    for (int i = 0; i < std::min(string_length, str.string_length); i++) 
    {
        if (string_content[i] > str.string_content[i])
        {
            return 1;
        }
        else if (string_content[i] < str.string_content[i])
        {
            return -1;
        }
    }

    if (string_length == str.string_length) 
    {
        return 0;
    }
    else if (string_length > str.string_length)
    {
        return 1;
    }

    return -1;
}


int main()
{
    EngineLeak::LeakCheck();

    MyString str1("this is a very very long string");
    std::cout << "Location of first <very> in the string : " << str1.find(0, "very")
        << std::endl;
    std::cout << "Location of second <very> in the string : "
        << str1.find(str1.find(0, "very") + 1, "very") << std::endl;

    // 컴파일러가 알아서 인자 타입을 변환하는 과정을 암시적 변환이라고 한다.(implicit conversion)
    // 하지만 의도하지 않는 자료형으로 변한을 막는 것또한 있을것이다. 그걸 explicit으로 막을 수 있다.
    // 즉, 원하지 않는 자료형으로 변한을 막는 것이다.


    return 0;
    {
        MyString str1("very long string");
        MyString str2("<some string inserted between>");
        str1.reserve(30);

        std::cout << "Capacity : " << str1.Buffer() << std::endl;
        std::cout << "String length : " << str1.Size() << std::endl;
        str1.println();

        str1.insert(5, str2);
        str1.println();
    }



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
