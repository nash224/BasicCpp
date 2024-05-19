#include "PreCompile.h"
#include "CoreObject.h"

#include "GameEngineCore.h"
#include "GameEngineObjectManager.h"

#include "GameSet.h"

CoreObject::CoreObject() 
{
}

CoreObject::~CoreObject() 
{
}

void CoreObject::Start()
{
	GameEngineObjectManager* pObjectManager = GameEngineCore::GetObjectManagerPointer();
	if (nullptr == pObjectManager)
	{
		MsgBoxAssert("오브젝트 매니저가 존재하지 않습니다.");
		return;
	}

	std::shared_ptr<GameSet> pObject = pObjectManager->CreateObject<GameSet>();
}
