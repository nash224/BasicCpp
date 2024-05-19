#include "PreCompile.h"
#include "GameEngineObjectManager.h"

#include "GameEngineObject.h"


GameEngineObjectManager::GameEngineObjectManager()
{
}

GameEngineObjectManager::~GameEngineObjectManager() 
{
}

void GameEngineObjectManager::Init(const std::shared_ptr<class GameEngineObject>& _Object, std::int32_t _Order)
{
	_Object->Start();
	_Object->SetOrder(_Order);
}

void GameEngineObjectManager::AllUpdate(float _DeltaTime)
{
	for (std::pair<std::int32_t, std::list<std::shared_ptr<GameEngineObject>>> Pair : AllObjects)
	{
		std::list<std::shared_ptr<GameEngineObject>> ObjectGroup = Pair.second;

		for (const std::shared_ptr<GameEngineObject>& Object : ObjectGroup)
		{
			Object->Update(_DeltaTime);
		}
	}
}

void GameEngineObjectManager::Release()
{
	AllObjects.clear();
}