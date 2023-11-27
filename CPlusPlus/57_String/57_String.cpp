// 57_String.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

// std::string
//      - basic_string의 클래스 템플릿의 인스턴스화 버전이다.
//      - CharT 타입의 객체를 메모리에 연속적으로 저장한다.
//      - CharT 자리에
// template <class CharT, class Traits = std::char_traits<CharT>,
//     class Allocator = std::allocator<CharT>>
// class basic_string;

// class CharT
// std::string			std::basic_string<char>
// std::wstring			std::basic_string<wchar_t>
// std::u16string		std::basic_string<char16_t>
// std::u32string		std::basic_string<char32_t>

// class Traits = std::char_traits<CharT>
//	- 기본적인 문자열 연산을 가지고 있는 클래스

// 로직을 분리한 이유
// => 사용자에게 자유를 부여하기 위해서
//	ex) 대소문자 구분하지 않는 버전을 만들때 Traits를 바꿔주면 됨
//		=> CharT는 같지만, Traits는 다른 경우

// Stateless  : 멤버 변수가 없는 static 함수로 이루어진 구조체
struct myCharTraits : public std::char_traits<char>
{
public:
	static int get_real_rank(char _c)
	{
		if (isdigit(_c))
		{
			return _c + 256;
		}
	}

	static bool lt(char _Left, char _Right)
	{
		return get_real_rank(_Left) < get_real_rank(_Right);
	}

	static int compare(const char* _Str1, const char* _Str2, size_t _Size)
	{
		while (_Size-- != 0)
		{
			if ((*_Str1) < (*_Str2))
			{
				return -1;
			}

			if ((*_Str1) > (*_Str2))
			{
				return 1;
			}

			++_Str1;
			++_Str2;
		}

		return 0;
	}
};

void* operator new(std::size_t _count)
{
	std::cout << _count << " bytes 할당" << std::endl;
	return malloc(_count);
}

// 만약 모든 문자열을 동적메모리를 할당받는다고하면
// 길이가 짧은 문자열을 여러번 할당받는것이 비효율적이다.
// SSO(short string optimization) 짧은 길이 문자열일 경우, 문자 데이터를 할당하고 객체 자체에 저장한다.


int main()
{
	if (bool IsExecute = false)
	{
		std::basic_string<char, myCharTraits> my_s1 = "1a";
		std::basic_string<char, myCharTraits> my_s2 = "a1";

		std::cout << "숫자의 우선순위가 더 낮은 문자열 : " << std::boolalpha
			<< (my_s1 < my_s2) << std::endl;

		std::string s1 = "1a";
		std::string s2 = "a1";

		std::cout << "일반 문자열 : " << std::boolalpha << (s1 < s2) << std::endl;
	}

	if (bool IsExecute = true)
	{
		std::cout << "s1 생성 --- " << std::endl;
		std::string s1 = "this is a pretty long sentence!!!";
		std::cout << "s1 크기 : " << sizeof(s1) << std::endl;

		std::cout << "s2 생성 --- " << std::endl;
		std::string s2 = "short sentence";
		std::cout << "s2 크기 : " << sizeof(s2) << std::endl;
	}
}
