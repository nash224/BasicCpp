#include "PreCompile.h"
#include "GameEngineRandom.h"

GameEngineRandom::GameEngineRandom() 
{
}

GameEngineRandom::~GameEngineRandom() 
{
}

int GameEngineRandom::RandomInt(int _Min, int _Max)
{
	std::uniform_int_distribution<int> Generator(_Min, _Max);
	return Generator(MtGen);
}