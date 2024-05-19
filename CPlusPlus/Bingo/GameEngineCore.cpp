#include "PreCompile.h"
#include "GameEngineCore.h"

#include "GameEngineTime.h"
#include "GameEngineScreen.h"
#include "GameEngineObjectManager.h"
#include "GameEngineObject.h"
#include "CoreObject.h"

#include <locale.h>

#define FRAME 1.f / 6.0f

GameEngineTime GameEngineCore::s_MainTime;
GameEngineScreen GameEngineCore::s_MainRender;
GameEngineObjectManager GameEngineCore::s_MainObjectManager;
bool GameEngineCore::s_bUpdateValue = true;
bool GameEngineCore::s_bOutValue = false;
float GameEngineCore::s_fStateTime = 0.0f;
GameEngineCore::GameEngineCore() 
{
}

GameEngineCore::~GameEngineCore() 
{
}

void GameEngineCore::EngineStart()
{
	Debug::LeakCheck();

	std::locale::global(std::locale("kor"));

	GameEngineInput::Initialize();
	s_MainRender.CreateBuffer(10, 10);
	s_MainObjectManager.CreateObject<CoreObject>();

	Loop();
	Release();
}

void GameEngineCore::Loop()
{
	while (true == s_bUpdateValue)
	{
		s_MainTime.Update();
		const float fDeltaTime = s_MainTime.GetDeltaTime();
		s_fStateTime += fDeltaTime;

		GameEngineInput::Update();

		s_MainObjectManager.AllUpdate(fDeltaTime);

		if (s_fStateTime > FRAME)
		{
			s_fStateTime = 0.0f;

			s_MainRender.Clear();
			s_MainRender.Render();

			if (true == s_bOutValue)
			{
				Stop();
			}
		}
	}
}

void GameEngineCore::Release()
{
	GameEngineInput::Release();
	s_MainRender.Release();
	s_MainObjectManager.Release();
}
