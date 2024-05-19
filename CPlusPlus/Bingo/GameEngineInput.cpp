#include "PreCompile.h"
#include "GameEngineInput.h"


std::map<std::uint32_t, GameEngineInput::InputKey> GameEngineInput::AllKeys;
GameEngineInput::GameEngineInput() 
{
}

GameEngineInput::~GameEngineInput() 
{
}

void GameEngineInput::Initialize()
{
	AllKeys[VK_ESCAPE] = InputKey(VK_ESCAPE);
	AllKeys[VK_BACK] = InputKey(VK_BACK);
	AllKeys[VK_RETURN] = InputKey(VK_RETURN);

	for (std::uint32_t i = 'A'; i <= static_cast<std::uint32_t>('Z'); i++)
	{
		AllKeys[i] = InputKey(i);
	}

	for (std::uint32_t i = '0'; i <= static_cast<std::uint32_t>('9'); i++)
	{
		AllKeys[i] = InputKey(i);
	}

	Reset();
}

void GameEngineInput::Update()
{
	std::map<std::uint32_t, InputKey>::iterator StartIter = AllKeys.begin();
	std::map<std::uint32_t, InputKey>::iterator EndIter   = AllKeys.end();

	for (; StartIter != EndIter; StartIter++)
	{
		(*StartIter).second.Update();
	}
}

void GameEngineInput::Reset()
{
	std::map<std::uint32_t, InputKey>::iterator StartIter = AllKeys.begin();
	std::map<std::uint32_t, InputKey>::iterator EndIter = AllKeys.end();

	for (; StartIter != EndIter; StartIter++)
	{
		(*StartIter).second.Reset();
	}
}

void GameEngineInput::Release()
{
	AllKeys.clear();
}

GameEngineInput::InputKey* GameEngineInput::FindKey(std::uint32_t _Key)
{
	std::map<std::uint32_t, GameEngineInput::InputKey>::iterator FindIter = AllKeys.find(_Key);
	if (AllKeys.end() == FindIter)
	{
		MsgBoxAssert("등록되지 않은 키를 입력했습니다.");
		return nullptr;
	}
	
	GameEngineInput::InputKey* pKey = &FindIter->second;
	return pKey;
}

bool GameEngineInput::IsPress(std::uint32_t _Key)
{
	return FindKey(_Key)->IsPress();
}

bool GameEngineInput::IsFree(std::uint32_t _Key)
{
	return FindKey(_Key)->IsFree();
}

bool GameEngineInput::IsDown(std::uint32_t _Key)
{
	return FindKey(_Key)->IsDown();
}

bool GameEngineInput::IsUp(std::uint32_t _Key)
{
	return FindKey(_Key)->IsUp();
}

void GameEngineInput::InputKey::Update()
{
	if (true == InputCheck())
	{
		if (false == PressValue)
		{
			PressValue = true;
			FreeValue = false;
			DownValue = true;
			UpValue = false;
		}
		else
		{
			PressValue = true;
			FreeValue = false;
			DownValue = false;
			UpValue = false;
		}
	}
	else
	{
		if (false == FreeValue)
		{
			PressValue = false;
			FreeValue = true;
			DownValue = false;
			UpValue = true;
		}
		else
		{
			PressValue = false;
			FreeValue = true;
			DownValue = false;
			UpValue = false;
		}
	}
}
