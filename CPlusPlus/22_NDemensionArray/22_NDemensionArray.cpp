// 22_NDemensionArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\00_Leak\LeakCheck.h"


// 동일한 인자 타입 함수는 리턴타입을 하나만 받을 수 있다.


namespace MyArray
{
    class Array;
    class Int;

    class Array
    {
        friend class Int;
        friend class Iterator;

    public:
        Array(int _Dim, int* _ArraySize)
            : Dim(_Dim)
        {
            Size = new int[Dim];

            for (int i = 0; i < Dim; i++)
            {
                Size[i] = _ArraySize[i];
            }

            Top = new Address;
            Top->Level = 0;

            Initialize_Address(Top);
        }

        Array(const Array& _Other)
            : Dim(_Other.Dim)
        {
            Size = new int[Dim];

            for (int i = 0; i < Dim; i++)
            {
                Size[i] = _Other.Size[i];
            }

            Top = new Address;
            Top->Level = 0;

            Initialize_Address(Top);

            Copy_Address(Top, _Other.Top);
        }

        ~Array();

        Int operator[](const int _Index);

    private:
        // 몇차원?
        const int Dim;

        // 담고 있는  배열의 크기는 얼마?
        int* Size;

        struct Address
        {
            int Level;
            void* next;
        };

        Address* Top;

        void Initialize_Address(Address* _Current);
        void Copy_Address(Address* _Dest, Address* _Src);
        void Delete_Address(Address* _Current);


        class Iterator
        {
            int* location;
            Array* Arr;


            Iterator(Array* arr, int* loc = nullptr) 
                : Arr(arr) 
            {
                location = new int[arr->Dim];
                for (int i = 0; i != arr->Dim; i++)
                {
                    location[i] = (loc != nullptr ? loc[i] : 0);
                }
            }

            Iterator(const Iterator& itr) 
                : Arr(itr.Arr)
            {
                location = new int[Arr->Dim];
                for (int i = 0; i != Arr->Dim; i++)
                {
                    location[i] = itr.location[i];
                }
            }

            ~Iterator() { delete[] location; }
            // 다음 원소를 가리키게 된다.


            Iterator& operator++()
            {
                if (location[0] >= Arr->Size[0])
                {
                    return (*this);
                }

                bool carry = false;
                int i = Arr->Dim - 1;

                do
                {
                    location[i]++;

                    if (location[i] >= Arr->Size[i] && i >= 1)
                    {
                        location[i] -= Arr->Size[i];

                        carry = true;
                        --i;
                    }
                    else
                    {
                        carry = false;
                    }
                } while (true == carry && i >= 0);

                return (*this);
            }

            Iterator& operator++(int)
            {
                Iterator itr(*this);
                ++(*this);
                return itr;
            }

            Int operator*();

            Iterator begin()
            {
                int* ReturnIter = new int[Arr->Dim];
                for (int i = 0; i < Arr->Dim; i++)
                {
                    ReturnIter[i] = 0;
                }

                Iterator temp(Arr, ReturnIter);
                delete[] ReturnIter;

                return temp;
            }

            Iterator end()
            {
                int* EndIter = new int[Arr->Dim];
                EndIter[0] = Arr->Size[0];
                for (int i = 1; i < Arr->Dim; i++)
                {
                    EndIter[i] = 0;
                }

                Iterator temp(Arr, EndIter);
                delete[] EndIter;

                return temp;
            }
        };

    };

    Array::~Array()
    {
        Delete_Address(Top);
        delete[] Size;
    }

    void Array::Initialize_Address(Address* _Current)
    {
        if (nullptr == _Current)
        {
            return;
        }

        if (_Current->Level == Dim - 1)
        {
            _Current->next = new int[Size[_Current->Level]];
            return;
        }

        _Current->next = new Address[Size[_Current->Level]];
        for (int i = 0; i != Size[_Current->Level]; i++)
        {
            Address* NewAddress = (static_cast<Address*>(_Current->next) + 1);
            NewAddress->Level = _Current->Level + 1;
            Initialize_Address(NewAddress);
        }
    }

    void Array::Copy_Address(Address* _Dest, Address* _Src)
    {
        if (nullptr == _Src)
        {
            return;
        }

        if (_Dest->Level == Dim - 1)
        {
            for (int i = 0; i < Size[_Dest->Level]; i++)
            {
                static_cast<int*>(_Dest->next)[i] = static_cast<int*>(_Src->next)[i];
                return;
            }
        }

        for (int i = 0; i < Size[_Dest->Level]; i++)
        {
            Address* DestAddress = static_cast<Address*>(_Dest->next) + i;
            Address* SrcAddress = static_cast<Address*>(_Src->next) + i;

            Copy_Address(DestAddress, SrcAddress);
        }
    }

    void Array::Delete_Address(Address* _Current)
    {
        if (nullptr == _Current)
        {
            return;
        }

        if (_Current->Level != Dim - 1)
        {
            for (int i = 0; i < Size[_Current->Level]; i++)
            {
                Address* NextAddress = static_cast<Address*>(_Current->next) + i;
                Delete_Address(NextAddress);
            }
        }

        if (_Current->Level == Dim - 1)
        {
            delete[] static_cast<int*>(_Current->next);
        }

        delete[] static_cast<Address*>(_Current->next);
    }

    class Int
    {
    public:
        operator int()
        {
            if (nullptr != Data)
            {
                return *static_cast<int*>(Data);
            }

            return 0;
        }

        Int& operator=(const int& _Value)
        {
            if (nullptr != Data)
            {
                *static_cast<int*>(Data) = _Value;
            }

            return *this;
        }

    private:
        void* Data;

        int Level;

        Array* RefArray;

    public:

        Int(int _Index, int _Level , void* _Data, Array* _RefArray)
            : Level(_Level), Data(_Data), RefArray(_RefArray)
        {
            if (_Level < 1 || _Index >= RefArray->Size[_Level - 1])
            {
                Data = nullptr;
                return;
            }

            if (Level == RefArray->Dim)
            {
                void* RefAddress = static_cast<Array::Address*>(Data)->next;
                Data = static_cast<int*>(RefAddress) + _Index;
            }
            else
            {
                void* RefAddress = static_cast<Array::Address*>(Data)->next;
                Data = static_cast<Array::Address*>(RefAddress) + _Index;
            }
        }

        Int(const Int& _Value) : Data(_Value.Data), Level(_Value.Level), RefArray(_Value.RefArray) {}

        Int operator[](const int _Index)
        {
            if (nullptr == Data)
            {

            }

            return Int(_Index, Level + 1, Data, RefArray);
        }
    };


    Int Array::operator[](const int _Index)
    {
        return Int(_Index, 1, static_cast<void*>(Top), this);
    }

    Int Array::Iterator::operator*()
    {
        Int StartIter = Arr->operator[](location[0]);
        for (int i = 1; i < Arr->Dim - 1; i++)
        {
            StartIter = Arr->operator[](location[i]);
        }

        return StartIter;
    }

}

int main()
{
    EngineLeak::LeakCheck();

    int size[] = { 2, 3, 4 };
    MyArray::Array arr(3, size);

    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            for (int k = 0; k < 4; k++) 
            {
                arr[i][j][k] = (i + 1) * (j + 1) * (k + 1);
            }
        }
    }
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            for (int k = 0; k < 4; k++) 
            {
                std::cout << i << " " << j << " " << k << " " << arr[i][j][k] << std::endl;
            }
        }
    }

    return 0;

    int** Arr;
    Arr = new int* [5];
    for (int i = 0; i < 5; i++)
    {
        Arr[i] = new int[9];
    }
    Arr[3][2] = 6;

    for (int i = 0; i < 5; i++)
    {
        delete[] Arr[i];
    }

    delete[] Arr;

    std::cout << "Hello World!\n";
}
