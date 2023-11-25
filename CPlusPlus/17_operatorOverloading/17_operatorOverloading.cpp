// 17_operatorOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// C에서는 기본 데이터 타입만 연산자가 가능했다.
//      => 구조체 변수에 사용자 정의 연산자를 사용하는 것은 불가능 했다.
// 
// c++에서는 가능하다.

// 오버로딩 : 사용자가 직접 연산자를 정의할 수 있다.
// (리턴 타입) operator(연산자) (연산자가 받는 인자)

// 실수의 제곱은 언제나 양수이다.
// 음수의 제곱근은 실수로 표현할 수 없다.
// 
// 허수 = 음수 제곱근을 표현하기 위해 특별한 수를 정의함
// 허수에서 -1의 제곱근을 i 로 표현한다.

// 복소수 == 실수와 허수를 포함하는 수 체계이다.

#include <iostream>

class Complex {
private:
    double real;
    double img;

public:
    Complex(double real, double img) 
        :
        real(real), 
        img(img) 
    {

    }

    Complex(const Complex& c) 
    {
        real = c.real, img = c.img; 
    }

    Complex(const char* str);

    // 사칙 연산자는 값을 리턴해야한다. 
    // (Complex형을 리턴한다) (연산자는 +) (인자는 c의 레퍼런스를 가져오되 const로 수정할 수 없다. => 읽기만 가능) (const 함수 => 멤버를 변경할 수 없다.)
    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;


    // 지워져도 컴파일러가 알아서 지원해준다. 
    //Complex operator+(const char* _str) const;
    //Complex operator-(const char* _str) const;
    //Complex operator*(const char* _str) const;
    //Complex operator/(const char* _str) const;

    // 불필요한 연산을 방지하고자 레퍼런스를 사용한다.
    // 하지만 대입연산자를 따로 지정해두지 않아도 컴파일러가 제공하는 얕은 복사 디폴트 대입 연산자를 지원하고 있다.
    // 만약 내부에 동적할당한 포인터가 있다면 깊은 복사를 해줘야한다.
    Complex& operator=(const Complex& c);

    // 대입 사칙연산자는 기존에 사칙연산자를 만들어 놓았다면 쉽게 구현할 수 있다.
    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);


    double get_number(const char* str, int from, int to) const;

    void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }


    friend std::ostream& operator<<(std::ostream& _os, const Complex& _c);
};

Complex Complex::operator+(const Complex& c) const 
{
    Complex temp(real + c.real, img + c.img);
    return temp;
}

Complex Complex::operator-(const Complex& c) const
{
    Complex temp(real - c.real, img - c.img);
    return temp;
}

Complex Complex::operator*(const Complex& c) const
{
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}

Complex Complex::operator/(const Complex& c) const 
{
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

Complex& Complex::operator=(const Complex& c)
{
    real = c.real;
    img = c.img;
    return *this;
}


Complex& Complex::operator+=(const Complex& c) 
{
    (*this) = (*this) + c;
    return *this;
}

Complex& Complex::operator-=(const Complex& c) 
{
    (*this) = (*this) - c;
    return *this;
}

Complex& Complex::operator*=(const Complex& c) 
{
    (*this) = (*this) * c;
    return *this;
}

Complex& Complex::operator/=(const Complex& c)
{
    (*this) = (*this) / c;
    return *this;
}

double Complex::get_number(const char* str, int from, int to) const
{
    bool minus = false;
    if (from > to)
    {
        return 0;
    }

    if (str[from] == '-')
    {
        minus = true;
    }

    if (str[from] == '-' || str[from] == '+')
    {
        ++from;
    }

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++)
    {
        if (isdigit(str[i]) && true == integer_part)
        {
            num *= 10.0;
            num += (str[i] - '0');
        }
        else if (str[i] == '.')
        {
            integer_part = false;
        }
        else if (isdigit(str[i]) && false == integer_part)
        {
            decimal /= 10.0;
            num += (str[i] - '0') * decimal;
        }
        else
        {
            break;
        }
    }

    if (true == minus)
    {
        num *= -1.0;
    }

    return num;
}

Complex::Complex(const char* str) 
{
    int begin = 0, end = static_cast<int>(strlen(str));
    img = 0.0;
    real = 0.0;

    int pos_i = -1;
    for (int i = 0; i != end; i++) 
    {
        if (str[i] == 'i') 
        {
            pos_i = i;
            break;
        }
    }

    if (pos_i == -1) 
    {
        real = get_number(str, begin, end - 1);
        return;
    }

    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

std::ostream& operator<<(std::ostream& _os, const Complex& _c)
{
    _os << " ( " << _c.real << " , " << _c.img << " ) ";
    return _os;
}


int main() {

    {
        Complex a(0, 0);
        a = a + "-1.1 + i3.923" ;
        // 컴파일러가 다음 순위로 오버로딩될 수 있는 함수를 찾아 알아서 변환해준다.
        // 만약 Complex(char* str) 이라면 변환이 이루어지지 않는데
        // 저 받는 값 자체가 문자열 리터럴이기 때문이다.
        /*a = a.operator+(Complex("-1.1 + i3.923"));*/
        a.println();
        a = a - "1.2 -i1.823";
        a.println();
        a = a * "2.3+i22";
        a.println();
        a = a / "-12+i55";
        a.println();

        std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;
    }


    return 0;


    {
        Complex a(0, 0);
        a.println();
    }

    return 0;
}



// Some_Class a = b;     //복사 연산자 호출
// Some_Class a;        // 기본 생성자 호출 후, 대입 연산자 
// a = b;


// 연산자 오브로딩은 개별적으로 정의가 필요한 함수이다.


