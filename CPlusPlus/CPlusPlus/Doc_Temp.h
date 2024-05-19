#pragma once
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <list>

class GameEngineObjectBase
{
public:
	template<typename EnumType>
	void SetOrder(EnumType _Order)
	{
		SetOrder(static_cast<int>(_Order));
	}
	int GetOrder()
	{
		return Order;
	}

	virtual void On()
	{
		IsUpdateValue = true;
	}
	virtual void Off()
	{
		IsUpdateValue = false;
	}
	virtual void OnOffSwitch()
	{
		IsUpdateValue = !IsUpdateValue;
	}

	void Death()
	{
		this->IsDeathValue = true;
	}
	virtual bool IsUpdate()
	{
		return true == IsUpdateValue && false == IsDeathValue;
	}
	virtual bool IsDeath()
	{
		return IsDeathValue;
	}

	void SetName(std::string_view _Name)
	{
		Name = _Name.data();
	}
	std::string GetName()
	{
		return Name;
	}


protected:
	std::string Name;

	int Order = 0;
	bool IsUpdateValue = true;
	bool IsDeathValue = false;
};

class GameEngineTransform
{

};

class GameEngineObject;
GameEngineObject::GameEngineObject() {}
GameEngineObject ::~GameEngineObject() {}

// 설명 :
class GameEngineObject : public GameEngineObjectBase, public std::enable_shared_from_this<GameEngineObject>
{
	friend class GameEngineLevel;
	friend class GameEngineCore;

public:
	GameEngineTransform Transform;

	// constrcuter destructer
	GameEngineObject();
	virtual ~GameEngineObject();

	// delete Function
	GameEngineObject(const GameEngineObject& _Other) = delete;
	GameEngineObject(GameEngineObject&& _Other) noexcept = delete;
	GameEngineObject& operator=(const GameEngineObject& _Other) = delete;
	GameEngineObject& operator=(GameEngineObject&& _Other) noexcept = delete;

	virtual void Start() {}
	virtual void Update(float _Delta) {}
	virtual void Release() {}

	template<typename ChildType>
	std::shared_ptr<GameEngineObject> CreateChild(int _Order)
	{
		std::shared_ptr<GameEngineObject> NewChild = std::make_shared<ChildType>();
		NewChild->SetOrder(_Order);
		NewChild->SetParent(this, _Order);
		NewChild->Start();
		return NewChild;
	}
	void SetParent(GameEngineObject* _Parent, int _Order)
	{
		Parent = _Parent;
		Parent->Childs[_Order].push_back(shared_from_this());
		Transform.SetParent(_Parent->Transform);
	}

	template<typename ConvertType>
	std::shared_ptr<ConvertType> GetDynamic_Cast_This()
	{
		std::shared_ptr<GameEngineObject> ObjectPtr = shared_from_this();
		std::shared_ptr<ConvertType> CameraPtr = std::dynamic_pointer_cast<ConvertType>(ObjectPtr);

		if (nullptr == CameraPtr)
		{
			// MsgBoxAssert("다이나믹 캐스트에 실패했습니다. 가상함수 테이블 부모가 누구인지 확인해보세요. 혹은 부모 생성자에서는 사용이 불가능한 함수입니다.");
			return nullptr;
		}

		return CameraPtr;
	}

	bool IsUpdate() override
	{
		return Parent == nullptr ? true == IsUpdateValue && false == IsDeathValue : Parent->IsUpdate() && true == IsUpdateValue && false == IsDeath();
	}
	bool IsDeath() override
	{
		return Parent == nullptr ? IsDeathValue : Parent->IsDeath() || IsDeathValue;
	}

protected:
	GameEngineObject* Parent = nullptr;
	std::map<int, std::list<std::shared_ptr<class GameEngineObject>>> Childs;

};