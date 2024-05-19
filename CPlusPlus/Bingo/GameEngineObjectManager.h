#pragma once
#include "GameEngineObject.h"

// Ό³Έν :
class GameEngineObjectManager
{
	friend class GameEngineCore;

public:
	void AllUpdate(float _DeltaTime);
	void Release();

	template<typename ConvertType, typename Enumtype>
	std::shared_ptr<ConvertType> CreateObject(Enumtype _Order)
	{
		return CreateObject<ConvertType>(static_cast<std::int32_t>(_Order));
	}

	template<typename ConvertType>
	std::shared_ptr<ConvertType> CreateObject(std::int32_t _Order = 0)
	{
		std::shared_ptr<ConvertType> NewObject = std::make_shared<ConvertType>();
		Init(NewObject, _Order);
		AllObjects[_Order].push_back(NewObject);
		return NewObject;
	}

	void Init(const std::shared_ptr<GameEngineObject>& _Object, std::int32_t _Order);

protected:

private:
	// constrcuter destructer
	GameEngineObjectManager();
	~GameEngineObjectManager();

	// delete Function
	GameEngineObjectManager(const GameEngineObjectManager& _Other) = delete;
	GameEngineObjectManager(GameEngineObjectManager&& _Other) noexcept = delete;
	GameEngineObjectManager& operator=(const GameEngineObjectManager& _Other) = delete;
	GameEngineObjectManager& operator=(GameEngineObjectManager&& _Other) noexcept = delete;

private:
	std::map<std::int32_t , std::list<std::shared_ptr<GameEngineObject>>> AllObjects;

};

