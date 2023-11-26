// 36_TemplateSpecialization.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


template <typename DataType>
class Vector
{
    DataType* Data;
    int Buffer;
    int Size;

public:

    typedef DataType value_type;

    Vector(int n = 1)
        : Data(new DataType[n]), Buffer(n), Size(0)
    {

    }

    void push_back(DataType s)
    {
        if (Buffer <= Size) {
            DataType* temp = new DataType[Buffer * 2];
            for (int i = 0; i < Size; i++)
            {
                temp[i] = Data[i];
            }
            delete[] Data;
            Data = temp;
            Buffer *= 2;
        }

        Data[Size] = s;
        Size++;
    }
};

template <>
class Vector<bool> 
{
    unsigned int* Data;
    int Buffer;
    int Size;

public:
    typedef bool value_type;

    // 생성자
    Vector(int n = 1)
        : Data(new unsigned int[n / 32 + 1]), Buffer(n / 32 + 1), Size(0)
    {
        for (int i = 0; i < Buffer; i++) 
        {
            Data[i] = 0;
        }
    }

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(bool s) 
    {
        if (Buffer * 32 <= Size) 
        {
            unsigned int* temp = new unsigned int[Buffer * 2];
            for (int i = 0; i < Buffer; i++) 
            {
                temp[i] = Data[i];
            }
            for (int i = Buffer; i < 2 * Buffer; i++) 
            {
                temp[i] = 0;
            }

            delete[] Data;
            Data = temp;
            Buffer *= 2;
        }

        if (s) 
        {
            Data[Size / 32] |= (1 << (Size % 32));
        }

        Size++;
    }

    bool operator[](int i)
    { 
        return (Data[i / 32] & (1 << (i % 32))) != 0;
    }

    void remove(int _Order) 
    {
        for (int i = _Order + 1; i < Size; i++)
        {
            int prev = i - 1;
            int curr = i;

            // 만일 curr 위치에 있는 비트가 1 이라면
            // prev 위치에 있는 비트를 1 로 만든다.
            if (Data[curr / 32] & (1 << (curr % 32)))
            {
                Data[prev / 32] |= (1 << (prev % 32));
            }
            // 아니면 prev 위치에 있는 비트를 0 으로 지운다.
            else 
            {
                unsigned int all_ones_except_prev = 0xFFFFFFFF;
                all_ones_except_prev ^= (1 << (prev % 32));
                Data[prev / 32] &= all_ones_except_prev;
            }
        }
        Size--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() 
    {
        return Size; 
    }
    ~Vector() 
    {
        if (nullptr != Data) 
        {
            delete[] Data;
        }
    }
};



int main()
{
    Vector<bool> bool_vec;
    bool_vec.push_back(true);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);

    std::cout << "-------- bool vector ---------" << std::endl;
    for (int i = 0; i < bool_vec.size(); i++) {
        std::cout << bool_vec[i];
    }
    std::cout << std::endl;
}
