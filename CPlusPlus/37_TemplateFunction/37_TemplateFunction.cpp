// 37_TemplateFunction.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 템플릿은 컴파일때 실행된다.

template <typename DataType>
DataType max(DataType& _a, DataType& _b)
{
	return _a > _b ? _a : _b;
}


template <typename DataType>
class Vector 
{
    DataType* Data;
    int Buffer;
    int Size;

public:
    // 생성자
    Vector(int _Count = 1)
        : Data(new DataType[_Count]), Buffer(_Count), Size(0)
    {

    }

    ~Vector()
    {
        if (nullptr != Data)
        {
            delete[] Data;
        }
    }

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(DataType _Element)
    {
        if (Buffer <= Size) {
            DataType* temp = new DataType[Buffer * 2];
            for (int i = 0; i < Size; i++) {
                temp[i] = Data[i];
            }
            delete[] Data;
            Data = temp;
            Buffer *= 2;
        }

        Data[Size] = _Element;
        Size++;
    }

    // 임의의 위치의 원소에 접근한다.
    DataType  operator[](int i)
    {
        return Data[i];
    }

    // x 번째 위치한 원소를 제거한다.
    void remove(int _Order) {
        for (int i = _Order + 1; i < Size; i++)
        {
            Data[i - 1] = Data[i];
        }
        Size--;
    }

    void swap(int _LeftIndex, int _RightIndex)
    {
        DataType temp = Data[_LeftIndex];
        Data[_LeftIndex] = Data[_RightIndex];
        Data[_RightIndex] = temp;
    }

    // 현재 벡터의 크기를 구한다.
    int size()
    {
        return Size;
    }
};

template<typename Container>
void Bubble_Sort(Container& _Container)
{
    for (int i = 0; i < _Container.size(); i++)
    {
        for (int j = 0; j < _Container.size(); j++)
        {
            if (_Container[i] > _Container[j])
            {
                _Container.swap(i, j);
            }
        }
    }
}



template <typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp) {
    for (int i = 0; i < cont.size(); i++) 
    {
        for (int j = i + 1; j < cont.size(); j++) 
        {
            if (!comp(cont[i], cont[j])) 
            {
                cont.swap(i, j);
            }
        }
    }
}


struct Compare 
{
    bool operator()(int a, int b) 
    {
        return a > b;
    }
};

struct CompareReverse 
{
    bool operator()(int a, int b) 
    {
        return a < b; 
    }
};





int main() 
{
    {
        Vector<int> int_vec;
        int_vec.push_back(3);
        int_vec.push_back(1);
        int_vec.push_back(2);
        int_vec.push_back(8);
        int_vec.push_back(5);
        int_vec.push_back(3);

        std::cout << "정렬 이전 ---- " << std::endl;
        for (int i = 0; i < int_vec.size(); i++) {
            std::cout << int_vec[i] << " ";
        }

        // 힘수 객체 (Functor) : 함수는 아니지만 함수와 비슷하게 사용할 수 있는 객체

        Compare comp1;
        bubble_sort(int_vec, comp1);

        std::cout << std::endl << std::endl << "내림차순 정렬 이후 ---- " << std::endl;
        for (int i = 0; i < int_vec.size(); i++) {
            std::cout << int_vec[i] << " ";
        }
        std::cout << std::endl;

        CompareReverse comp2;
        bubble_sort(int_vec, comp2);

        std::cout << std::endl << "오름차순 정렬 이후 ---- " << std::endl;
        for (int i = 0; i < int_vec.size(); i++) {
            std::cout << int_vec[i] << " ";
        }
        std::cout << std::endl;
    }


    return 0;

    {
        Vector<int> int_vec;
        int_vec.push_back(3);
        int_vec.push_back(1);
        int_vec.push_back(2);
        int_vec.push_back(8);
        int_vec.push_back(5);
        int_vec.push_back(3);

        std::cout << "정렬 이전 ---- " << std::endl;
        for (int i = 0; i < int_vec.size(); i++)
        {
            std::cout << int_vec[i] << " ";
        }

        std::cout << std::endl << "정렬 이후 ---- " << std::endl;
        Bubble_Sort(int_vec);
        for (int i = 0; i < int_vec.size(); i++)
        {
            std::cout << int_vec[i] << " ";
        }
        std::cout << std::endl;
    }

	return 0;

    {
        int a = 1, b = 2;
        // 인수를 명시하지 않아도 컴파일러가 인자 타입을 인식해 암묵적으로 변환해준다.
        std::cout << "Max (" << a << "," << b << ") ? : " << max(a, b) << std::endl;

        std::string s = "hello", t = "world";
        std::cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << std::endl;
    }
}