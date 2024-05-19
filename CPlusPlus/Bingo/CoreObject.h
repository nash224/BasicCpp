#pragma once
#include "GameEngineObject.h"

// Ό³Έν :
class CoreObject : public GameEngineObject
{
public:
	// constrcuter destructer
	CoreObject();
	~CoreObject();

	// delete Function
	CoreObject(const CoreObject& _Other) = delete;
	CoreObject(CoreObject&& _Other) noexcept = delete;
	CoreObject& operator=(const CoreObject& _Other) = delete;
	CoreObject& operator=(CoreObject&& _Other) noexcept = delete;

	void Start() override;

protected:

private:


};

