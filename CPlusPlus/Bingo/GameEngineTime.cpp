#include "PreCompile.h"
#include "GameEngineTime.h"

GameEngineTime::GameEngineTime() 
{
	CurTime = std::chrono::system_clock::now();
	PrevTime = CurTime;
}

GameEngineTime::~GameEngineTime() 
{
}

void GameEngineTime::Update()
{
	CurTime = std::chrono::system_clock::now();
	std::chrono::duration<double> sec = CurTime - PrevTime;
	PrevTime = CurTime;

	DoubleTime = sec.count();
	DeltaTime  = static_cast<float>(DoubleTime);
}

float GameEngineTime::GetDeltaTime() const
{
	return DeltaTime;
}
