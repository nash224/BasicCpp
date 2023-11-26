// 54_Ramda.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <functional>

class SomeClass 
{
    std::vector<int> vec;

    int num_erased;

public:
    SomeClass() 
    {
        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        num_erased = 1;

        vec.erase(std::remove_if(vec.begin(), vec.end(),
            [&/* 객체의 첫번째 요소인 this를 받음*/](int i) {
                if (num_erased >= 2)
                    return false;
                else if (i % 2 == 1) {
                    num_erased++;
                    return true;
                }
                return false;
            }),
            vec.end());
    }
};


int main()
{
    std::cout << "Hello World!\n";
}
