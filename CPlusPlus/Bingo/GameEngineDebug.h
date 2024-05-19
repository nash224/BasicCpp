#pragma once
#include <string>
#include <assert.h>

#define MsgBoxAssert(Msg) std::cout << Msg << std::endl;  \
        assert(false);                                    \
        
namespace Debug
{
	void LeakCheck();
}