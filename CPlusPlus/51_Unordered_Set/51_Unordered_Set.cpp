// 51_Unordered_Set.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <string>
#include <unordered_set>

// 각기 정렬되지 않은 다른 원소가 출력됨
// insert, find, erase가 O(1) 복잡도를 가짐
// 해시함수 : 새로운 원소가 삽입될때 어떤 상자에 들어갈지 결정함
// 같은 원소면 같은 메모리에 들어감 
// 다른 원소가 같은 해시 함수값을 가져서 같은 상자에 들어갈수도 있음

// unordered_set이나 unordered_map은 검색 또는 삽입할 때 해쉬 함수라는걸 사용
// 해시함수 : 임의의 크기를 가진 데이터를 고정된 크기의 데이터로 대응시켜줌
// 고정된 크기 : 일정 범위의 정수값 
// 
// 해시함수는 1~D까지 반환 
//      => 반환된 해시값을 원소를 저장할 상자의 번호로 지정
//      => 최대한 고르게 반환해줌
// 같은 원소를 함수에 전달할시 같은 해시값을 리턴

//  - 해시값 계산은 상수시간을 가짐
//  - 다른 원소가 같은 테이블에 있는 경우를 해시 충돌이라고 함
//  - 이런 해시 충돌이 자주일어나게 되면 최악의 경우 O(N)이라는 최악의 복잡도를 가짐
//  - 삽입되는 원사가 많아짐에 따라 해시 상자를 많이 만들게 되서 해시 함수를 바꿔줘야 하는데
//      모든 원소를 처음부터 끝까지 insert 해줘야함
//      => 이를 [rehash] 라고 함
//      => 복잡도는 O(N)        
//   - 즉, 해시 함수의 결과값이 특정 범위에 집중되어 있다면 최악의 복잡도가 나온다.


template <typename keyType>
void PrintUnorderedSet(const std::unordered_set<keyType>& _Key) 
{
    for (const keyType& Key: _Key)
    {
        std::cout << Key << std::endl;
    }
}


// 같은 상자에 다른 원소가 담겨있을 수도 있음으로
// 원소를 제거하고 싶을때 원소를 반복자로 찾고 지운다.
template <typename keyType>
void IsExist(std::unordered_set<keyType>& _USet, keyType _Key) 
{
    std::unordered_set<std::string>::const_iterator cFindIter = _USet.find(_Key);
    if (cFindIter != _USet.end())
    {
        std::cout << _Key << " 가 있습니다." << std::endl;
    }
    else 
    {
        std::cout << _Key << " 가 없습니다." << std::endl;
    }
}

// 객체를 unordered_map이나 unordered_set에 넣고 싶을때
// '해시 함수' 를 직접 만들어서 넣어준다.
// 해시 충돌 발생시 비교를 해야함으로 operator==()을 정의한다.

class Todo
{
public:
    Todo(int _Priority, const std::string& _JobDesc)
        : Priority(_Priority), JobDesc(_JobDesc)
    {

    }

    bool operator==(const Todo& _todo) const
    {
        if (Priority == _todo.Priority && JobDesc == _todo.JobDesc)
        {
            return true;
        }

        return false;
    }

    friend struct std::hash<Todo>;
    friend std::ostream& operator<<(std::ostream& _O, const Todo& _todo);

private:
    int Priority;
    std::string JobDesc;

};

template<>
struct std::hash<Todo>
{
    size_t operator()(const Todo& _todo) const
    {
        // 객체 함수
        hash<std::string> hash_func;

        // 해시값과 해시값 비교 연산
        return _todo.Priority ^ (hash_func(_todo.JobDesc));
    }
};

std::ostream& operator<<(std::ostream& _O, const Todo& _todo)
{
    _O << "중요도[" << _todo.Priority << "]" << _todo.JobDesc;
    return _O;
}


int main() 
{
    {
        std::unordered_set<Todo> TodoList;

        TodoList.insert(Todo(1, "농구 하기"));
        TodoList.insert(Todo(2, "수학 숙제 하기"));
        TodoList.insert(Todo(1, "프로그래밍 프로젝트"));
        TodoList.insert(Todo(3, "친구 만나기"));
        TodoList.insert(Todo(2, "영화 보기"));

        PrintUnorderedSet(TodoList);
        std::cout << "----------------" << std::endl;
    }

    return 0;

    {
        std::unordered_set<std::string> USet;

        USet.insert("hi");
        USet.insert("my");
        USet.insert("name");
        USet.insert("is");
        USet.insert("psi");
        USet.insert("welcome");
        USet.insert("to");
        USet.insert("c++");

        PrintUnorderedSet(USet);

        std::cout << "----------------" << std::endl;
        IsExist(USet, std::string("c++"));
        IsExist(USet, std::string("c"));

        std::cout << "----------------" << std::endl;
        std::cout << "'hi' 를 삭제" << std::endl;
        USet.erase(USet.find("hi"));
        IsExist(USet, std::string("hi"));
    }
}
