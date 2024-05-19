#include "CRandom.h"

namespace Engine
{
	CRandom::CRandom()
	{
	}

	CRandom::~CRandom()
	{
	}

	int CRandom::RandomInt(int _Min, int _Max)
	{
		std::uniform_int_distribution<int> Generator(_Min, _Max);
		return Generator(MtGen);
	}
}