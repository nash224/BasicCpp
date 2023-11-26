// 53_Remove.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>


template <typename Iter>
void Print(Iter _begin, Iter _end) 
{
    while (_begin != _end) {
        std::cout << "[" << *_begin << "] ";
        _begin++;
    }
    std::cout << std::endl;
}

struct IsOdd
{
    bool operator()(const int& _Value)
    {
        return _Value % 2 == 1;
    }
};

// remove_if 에 전달되는 함수객체의 경우 값이 달라지면 안된다. => 함수 객체가 여러번 복사될 수 있기 떄문이다.
struct IsOddTwo
{
public:
    IsOddTwo()
        : DeleteNum(0)
    {

    }

    bool operator()(const int& _iValue)
    {
        if (DeleteNum >= 2)
        {
            return false;
        }

        if (1 == _iValue % 2)
        {
            ++DeleteNum;
            return true;
        }

        return false;
    }


private:
    int DeleteNum;

};

// 객체가 복사됨으로 외부의 변수를 불러와 조건을 실행한다. 
//      => 하지만 객체의 복사비용이 발생함으로 비효율적으로 보인다.
struct IsOddPtr
{
public:
    IsOddPtr(int* _NumPtr)
        : DeleteNum(_NumPtr)
    {

    }

    bool operator()(const int& _iValue)
    {
        if (*DeleteNum >= 2)
        {
            return false;
        }

        if (1 == _iValue % 2)
        {
            ++(*DeleteNum);
            return true;
        }

        return false;
    }


private:
    int* DeleteNum;

};

int main()
{
    {
        std::vector<int> vec;
        vec.reserve(16);
        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        int DeleteCnt = 0;

        Print(vec.begin(), vec.end());
        // 람다식 : 이름없는 함수객체
        vec.erase(std::remove_if(vec.begin(), vec.end(), [](int _Value)->bool {return _Value % 2 == 1; }), vec.end());
        Print(vec.begin(), vec.end());

        // 람다함수로 함수객체 생성
        // 캡처목록[] 안에 변수를 집어넣으면 외부에서 변수를 가져와 사용할 수 있음
        // 캡처목록에 그냥 집어넣을 경우 변수 타입은 const 로 복사받는다.
        auto Func = [](int _Value)->bool {return _Value % 2 == 1; };
    }

    return 0;

    {
        std::vector<int> vec;
        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        int DeleteCnt = 0;

        Print(vec.begin(), vec.end());
        vec.erase(std::remove_if(vec.begin(), vec.end(), IsOddPtr(&DeleteCnt)), vec.end());
        Print(vec.begin(), vec.end());
    }

    return 0; 

    {
        std::vector<int> vec;
        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        Print(vec.begin(), vec.end());
        // remove_if의 3번째 인자는 조건을 설명할 함수객체를 받는다.
        vec.erase(std::remove_if(vec.begin(), vec.end(), IsOdd()), vec.end());
        Print(vec.begin(), vec.end());
    }

    return 0;


    {
        std::vector<int> vec;
        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        Print(vec.begin(), vec.end());

        // erase(Iterator); << 이터레이터가 가리키는 원소 제거
        // 베열에서 remove는 원소를 삭제하지 않고 뒤로 밀어버린다.
        vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());  // 뒤로 밀린 원소들은 erase함수에 의해 제거된다.

        Print(vec.begin(), vec.end());
    }
}