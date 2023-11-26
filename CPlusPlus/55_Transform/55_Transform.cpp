// 55_Transform.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>


template <typename Iter>
void Print(Iter _begin, Iter _end)
{
    while (_begin != _end) {
        std::cout << "[" << *_begin << "] ";
        _begin++;
    }
    std::cout << std::endl;
}

int main()
{
    
    std::vector<int> vec;
    vec.reserve(16);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    Print(vec.begin(), vec.end());

    // 특정 원소에 특정 객체 함수(predicate)를 실행하는것
    // 해석하자면 '시작과 끝 원소에 모두 1을 더하고 시작원소부터 덮어 씌워라'
    //      => 저장하는 컨테이너 크기가 최소한 같거나 커야한다.
    std::transform(vec.begin(), vec.end(), vec.begin(),
        [](int i) { return i + 1; });
    Print(vec.begin(), vec.end());
}
