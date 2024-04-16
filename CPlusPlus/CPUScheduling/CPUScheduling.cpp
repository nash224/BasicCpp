// CPUScheduling.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory>
#include <vector>

class Object : public std::enable_shared_from_this<Object>
{
public:
	void Init()
	{
		// DO
	}

	virtual void Start() = 0;
	virtual void Update() = 0;

private:

};

std::shared_ptr<Object> EngineStart::CoreObject;
bool EngineStart::UpdateValue = false;
class EngineStart
{
public:
	template<typename ObjectType>
	static void StartEngine()
	{
		std::shared_ptr<ObjectType> NewObject = std::make_shared<ObjectType>();
		NewObject->Start();
		CoreObject = NewObject;
		CoreObject->Update();
	}

private:
	static std::shared_ptr<Object> CoreObject;
	static bool UpdateValue;

};

class SchedulingModule
{
public:
	virtual void Transition() = 0;
	virtual void Do() = 0;

private:

};

class Start : public SchedulingModule
{
public:
	void Transition() override;
	void Do() override;
};

class CoreObject : public Object
{
public:
	void Start() override
	{
		// Create Object
	}

	void Update() override
	{
		UpdateValue = true;
		while (true == UpdateValue)
		{
			for (const std::shared_ptr<Object>& _Object : ChildObject)
			{
				_Object->Update();
			}
		}
	}

private:
	bool UpdateValue = false;
	std::vector<std::shared_ptr<Object>> ChildObject;

};

int main()
{
	EngineStart::StartEngine<CoreObject>();
}