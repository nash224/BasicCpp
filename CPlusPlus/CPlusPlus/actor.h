#pragma once
#include <memory>

class GameEngineCoreObject : public std::enable_shared_from_this<GameEngineCoreObject>
{

};

class GameEngineActor;
GameEngineActor::GameEngineActor() {}
GameEngineActor::~GameEngineActor() {}
class GameEngineLevel* GameEngineActor::GetLevel() {}
void GameEngineActor::ComponentInit(std::shared_ptr<class GameEngineComponent> _Component, int _Order) {}

// Ό³Έν :
class GameEngineActor : public GameEngineCoreObject
{
public:
	GameEngineActor();
	~GameEngineActor();

	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	template<typename ObjectType, typename EnumType>
	std::shared_ptr<ObjectType> CreateComponent(EnumType _Enum)
	{
		return CreateComponent<ObjectType>(static_cast<int>(_Enum));
	}

	template<typename ObjectType>
	std::shared_ptr<ObjectType> CreateComponent(int _Order = 0)
	{
		return std::dynamic_pointer_cast<ObjectType>(CreateChild<ObjectType>(_Order)); //std::dynamic_pointer_cast<ObjectType>(NewChild);
	}

	class GameEngineLevel* GetLevel();

protected:

private:
	void ComponentInit(std::shared_ptr<class GameEngineComponent> _Component, int _Order);

};