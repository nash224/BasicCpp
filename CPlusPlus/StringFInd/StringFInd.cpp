// StringFInd.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <string_view>
#include <map>


template<typename DataType>
void Print(DataType _Value)
{
	std::cout << _Value << std::endl;
}

template<typename DataType>
void Print(std::string_view _Msg, DataType _Value)
{
	std::cout << std::string(_Msg.data()) + ":" + std::to_string(_Value) << std::endl;
}

void Print(std::string_view _Msg, const std::string& _Value)
{
	std::cout << std::string(_Msg.data()) + ":" + _Value << std::endl;
}



template<typename DataType>
void Printf(std::string_view _MSG, DataType _Value)
{
	std::cout << _MSG << _Value << std::endl;
}

static std::string s_StrName = "Thisname";
int main()
{
	std::string StringName = "Map";
	std::string StringName1 = "Map1";
	std::string StringName2 = "Map2";
	std::map<std::string, int> StringSet;
	StringSet.insert(std::make_pair(StringName, 1));
	StringSet.insert(std::make_pair(StringName1, 3));
	StringSet.insert(std::make_pair(StringName2, 45));
	bool Value = StringSet.contains("Map");

	std::string CpyName = s_StrName;

	std::string* pStrName = &s_StrName;
	const char* CStr = s_StrName.c_str();

	Printf("Contain : ", (Value));
	Printf("StrName Pointer : ", (pStrName));
	Printf("Pointer Compare : ", (pStrName == &s_StrName));
	Printf("Pointer Compare : ", (CpyName.c_str() == CStr));
	Printf("Pointer Compare : ", (s_StrName.c_str() == CStr));


	std::cout << "Hello World";

	return 0;
	std::string Name = "a1s3d5f7h9zxcvbnmmqwerty1uio2468";
	size_t iFind0 = Name.find('1');
	size_t iFind1 = Name.find('2', 6);
	size_t iFind2 = Name.find_first_of("zxc");
	size_t iFind3 = Name.find_first_of("zxc", 1);
	size_t iFind6 = Name.find_last_not_of('6');
	

	Print("1Find", iFind0);
	Print("6 To 1Find", iFind1);
	Print("FFO zxc", iFind2);
	Print("10", Name[iFind2]);
	Print("FLNO 6", iFind6);
	Print("2 Str", Name.substr(10, 3));

	return 0;
}