#include "PreCompile.h"
#include "GameSet.h"

#include <sstream>

#include "Player.h"
#include "Bingo.h"
#include "UI_ConsoleMessage.h"

#define GAME_SYSTEM_MSG_1 L"Not Allow This Number. Please try again."
#define WIN_COUNT 5

GameSet::GameSet() 
{
}

GameSet::~GameSet() 
{
}

void GameSet::Start() 
{
	std::shared_ptr<Player> pPlayer = CreatePlayer(1, int2(4, 4));
	std::shared_ptr<Player> pPlayer2 = CreatePlayer(2, int2(26, 4));
	pPlayer->Init();
	pPlayer2->Init();

	std::shared_ptr<Bingo> pBingo = pPlayer->GetBoardPointer();
	if (nullptr == pBingo)
	{
		MsgBoxAssert("존재하지 않는 포인터를 참조하려 했습니다.");
		return;
	}

	mGameManager.SetBuffer(pBingo->GetBoardSize()); // GetBoardSize


	CreateConsoleMsg(int2(8, 17), L"Num 0 ~ 9 : 숫자 입력");
	CreateConsoleMsg(int2(8, 18), L"Enter : 입력");
	CreateConsoleMsg(int2(8, 19), L"BackSpace : 입력 취소");
	pSystemMSG = CreateConsoleMsg(int2(12, 16), L" ");

	int2 StartPos               = int2(12, 15);
	std::wstring Input_PrexWstr = std::wstring(L"입력한 수 : ");

	CreateConsoleMsg(StartPos, Input_PrexWstr);
	pInputMSG = UI_ConsoleMessage::CreateConsoleMsg(StartPos + int2(static_cast<std::uint32_t>(Input_PrexWstr.size()), 0), L"");
}

void GameSet::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown(VK_ESCAPE))
	{
		GameEngineCore::Stop();
	}

	InputUpdate();

	if (0.0f != fStateTime)
	{
		UpdateSystemMSG(_DeltaTime);
	}

	if (true == DeterWinner())
	{
		GameEngineCore::RenderOut();
	}
}

void GameSet::InputUpdate()
{
	bool InputCheck = false;

	if (false == InputCheck && true == GameEngineInput::IsDown(VK_BACK))
	{
		if (InputMSG.empty())
		{
			return;
		}

		InputMSG.pop_back();

		InputCheck = true;
	}

	if (false == InputCheck)
	{
		for (std::uint32_t i = '0'; i <= static_cast<std::uint32_t>('9'); i++)
		{
			if (true == GameEngineInput::IsDown(i))
			{
				if (5 < InputMSG.size())
				{
					break;
				}

				InputMSG.push_back(i);
				InputCheck = true;
			}
		}
	}

	if (false == InputCheck)
	{
		if (true == GameEngineInput::IsDown(VK_RETURN))
		{
			if (false == InputMSG.empty())
			{
				std::uint32_t i;
				std::wstringstream wssInt(InputMSG);
				wssInt >> i;

				GameSet::GameManager::ERuleCode CodeNumber = mGameManager.NumberCheck(i);
				switch (CodeNumber)
				{
				case GameSet::GameManager::Error:
					break;
				case GameSet::GameManager::Pass:
				{
					ReflectToPlayer(i);
				}
					break;
				case GameSet::GameManager::Duplication:
				{
					const float RenderTime = 3.0f;
					pSystemMSG->Print(GAME_SYSTEM_MSG_1);
					fStateTime = RenderTime;
				}
					break;
				default:
					break;
				}

				InputMSG.clear();
				InputCheck = true;
			}
		}
	}

	if (true == InputCheck)
	{
		InputRender();
	}
}

void GameSet::InputRender()
{
	pInputMSG->Print(L"     ");
	pInputMSG->Print(InputMSG);
}

void GameSet::ReflectToPlayer(std::uint32_t _Number)
{
	for (const std::shared_ptr<Player>& pPlayer : PlayerList)
	{
		pPlayer->Reflect(_Number);
	}
}

bool GameSet::DeterWinner()
{
	for (const std::shared_ptr<Player>& pPlayer : PlayerList)
	{
		std::shared_ptr<Bingo> pBingo = pPlayer->GetBoardPointer();
		if (nullptr == pBingo)
		{
			MsgBoxAssert("존재하지 않는 포인터를 참조했습니다.");
			return false;
		}

		std::uint32_t Count = pBingo->GetBingoCount();
		if (WIN_COUNT <= Count)
		{
			std::uint32_t WinnerNumber = pPlayer->GetPlayerNumber();

			ClearSystemMsg();
			pSystemMSG->Print(std::to_wstring(WinnerNumber) + L"Player is Winner");

			return true;
		}
	}

	return false;
}


void GameSet::UpdateSystemMSG(float _DeltaTime)
{
	fStateTime -= _DeltaTime;

	if (fStateTime < 0.0f)
	{
		fStateTime = 0.0f;
		ClearSystemMsg();
	}
}

void GameSet::ClearSystemMsg()
{
	std::uint32_t MSGSize = static_cast<std::uint32_t>(std::wstring(GAME_SYSTEM_MSG_1).size());
	std::wstring ClearMsg;

	ClearMsg.resize(MSGSize);
	for (std::uint32_t i = 0; i < MSGSize; i++)
	{
		ClearMsg.push_back(L' ');
	}
	pSystemMSG->Print(ClearMsg);
}

std::shared_ptr<class Player> GameSet::CreatePlayer(std::int32_t _PlayerNumber, int2 _Pos)
{
	GameEngineObjectManager* pObjectManager = GameEngineCore::GetObjectManagerPointer();
	if (nullptr == pObjectManager)
	{
		MsgBoxAssert("오브젝트 매니저가 존재하지 않습니다.");
		return nullptr;
	}

	std::shared_ptr<Player> pObject = pObjectManager->CreateObject<Player>(EUpdateOrder::Player);
	pObject->SetPosition(_Pos);
	pObject->SetPlayerNumber(_PlayerNumber);
	PlayerList.push_back(pObject);
	return pObject;
}

std::shared_ptr<class UI_ConsoleMessage> GameSet::CreateConsoleMsg(int2 _Pos, const std::wstring& _wStr)
{
	std::shared_ptr<UI_ConsoleMessage> pObject = UI_ConsoleMessage::CreateConsoleMsg(_Pos, _wStr);
	MessageList.push_back(pObject);
	return pObject;
}

GameSet::GameManager::ERuleCode GameSet::GameManager::NumberCheck(std::uint32_t _Number)
{
	if (false == DrawNumberList[_Number - 1])
	{
		DrawNumberList[_Number - 1] = true;
		return ERuleCode::Pass;
	}
	
	return ERuleCode::Duplication;
}
