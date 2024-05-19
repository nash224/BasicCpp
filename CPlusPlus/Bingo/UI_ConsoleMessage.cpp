#include "PreCompile.h"
#include "UI_ConsoleMessage.h"


std::shared_ptr<class UI_ConsoleMessage> UI_ConsoleMessage::CreateConsoleMsg(int2 _Pos, const std::wstring& _wStr)
{
	GameEngineObjectManager* pObjectManager = GameEngineCore::GetObjectManagerPointer();
	if (nullptr == pObjectManager)
	{
		MsgBoxAssert("오브젝트 매니저가 존재하지 않습니다.");
		return nullptr;
	}

	std::shared_ptr<UI_ConsoleMessage> pObject = pObjectManager->CreateObject<UI_ConsoleMessage>(EUpdateOrder::UI);
	pObject->SetPosition(_Pos);
	pObject->Print(_wStr);
	return pObject;
}

UI_ConsoleMessage::UI_ConsoleMessage() 
{
}

UI_ConsoleMessage::~UI_ConsoleMessage() 
{
}

void UI_ConsoleMessage::Print(const std::wstring& _wStr)
{
	Render(_wStr);
}

