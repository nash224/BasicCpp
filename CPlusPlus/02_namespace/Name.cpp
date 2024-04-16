#include "Name.h"

#include <iostream>

//  == using namespace를 소스파일에 선언해야되는 이유
// 
// using namespace를 헤더에 선언하면 
// 이 헤더를 호출한 다른 파일에서 스코프 설정 연산자 없이 쓸 수 있기 때문에
// 존재의의가 없어진다.
using namespace std;

void NS::foo()
{
	cout << "foo() called." << endl;
}
