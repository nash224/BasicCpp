// 55_Find.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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

class User
{
    friend class Party;

public:

    User(__int64 _Id, int _Level)
        : Id(_Id), Level(_Level)
    {

    }

    bool operator==(const User& _User)
    {
        if (_User.Id != Id)
        {
            return false;
        }

        if (_User.Level != Level)
        {
            return false;
        }

        return true;
    }


private:
    __int64 Id;
    int Level;

};

class Party
{
public:
    bool AddUser(const User& _User)
    {
        User NewUser(_User.Id, _User.Level);
        std::vector<User>::iterator FindIter = std::find(users.begin(), users.end(), NewUser);
        if (FindIter != users.end())
        {
            return false;
        }

        users.push_back(NewUser);
        return true;
    }

    bool IsEnterDungeon()
    {
        return std::all_of(users.begin(), users.end(), [&](const User& _user) 
            {
                return _user.Level >= 15;
            });
    }

    bool IsEnterRoom()
    {
        return std::any_of(users.begin(), users.end(), [&](const User& _user) 
            {
                return _user.Level >= 15;
            });
    }

private:
    std::vector<User> users;
};


int main()
{
    {
        Party party;
        party.AddUser(User(long long(643351), 15));
        party.AddUser(User(long long(643352), 13));
        party.AddUser(User(long long(643353), 17));
        party.AddUser(User(long long(643354), 12));

        std::cout << std::boolalpha;
        std::cout << "입장 가능 ? " << party.IsEnterDungeon() << std::endl;
        std::cout << "입장가능?" << party.IsEnterRoom()
            << std::endl;
    }

    return 0;

    {
        std::vector<int> vec;
        vec.reserve(16);

        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);


        std::vector<int>::iterator CurrentIter = vec.begin();
        while (true)
        {
            // std::find  : 차례대로 순회하면서 같은 원소를 가진 이터레이터를 반환 => 가장 먼저 찾은것을 리턴
            CurrentIter = std::find(CurrentIter, vec.end(), 3);
            if (CurrentIter == vec.end())
            {
                break;
            }
            std::cout << "3 은 " << std::distance(vec.begin(), CurrentIter) + 1 << " 번째 원소" << std::endl;
            ++CurrentIter;
        }

        // 컨테이너에서 지원해주는 find는 빠르다.
        // 알고리즘에서 지원하는 find의 비용은 O(N)이다.
    }
}
