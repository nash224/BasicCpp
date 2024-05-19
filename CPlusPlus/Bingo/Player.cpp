#include "PreCompile.h"
#include "Player.h"

#include "Bingo.h"
#include "UI_ConsoleMessage.h"

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start() 
{
	GameEngineObjectManager* pObjectManager = GameEngineCore::GetObjectManagerPointer();
	if (nullptr == pObjectManager)
	{
		MsgBoxAssert("오브젝트 매니저가 존재하지 않습니다.");
		return;
	}

	mpBingoBoard = pObjectManager->CreateObject<Bingo>(EUpdateOrder::Bingo);
}

void Player::Update(float _DeltaTime)
{

}

void Player::Init()
{
	int2 Pos = GetPosition();

	if (nullptr == mpBingoBoard)
	{
		MsgBoxAssert("존재하지 않는 포인터를 참조하려 했습니다.");
		return;
	}

	mpBingoBoard->SetPosition(Pos);
	mpBingoBoard->BoardRender();

	CreateConsoleMsg(Pos + int2(0, 6), std::to_wstring(mPlayerNumber) + L"Player");
	PrintBingoCount();
}

void Player::Reflect(std::uint32_t _iNumber)
{
	if (nullptr == mpBingoBoard)
	{
		MsgBoxAssert("존재하지 않는 포인터를 참조하려 했습니다.");
		return;
	}

	mpBingoBoard->Reflect(_iNumber);
	PrintBingoCount();
}

void Player::PrintBingoCount()
{
	if (nullptr == mpBingoBoard)
	{
		MsgBoxAssert("존재하지 않는 포인터를 참조하려 했습니다.");
		return;
	}

	int2 Pos                 = GetPosition();
	std::uint32_t BingoCount = mpBingoBoard->GetBingoCount();

	CreateConsoleMsg(Pos + int2(0, 7), std::wstring(L"빙고 : " + std::to_wstring(BingoCount)));
}


std::shared_ptr<class UI_ConsoleMessage> Player::CreateConsoleMsg(int2 _Pos, const std::wstring& _wStr)
{
	std::shared_ptr<UI_ConsoleMessage> pObject = UI_ConsoleMessage::CreateConsoleMsg(_Pos, _wStr);
	MessageList.push_back(pObject);
	return pObject;
}