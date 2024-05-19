#pragma once

// Ό³Έν :
class GameEngineCore
{
private:
	static class GameEngineTime s_MainTime;
	static class GameEngineScreen s_MainRender;
	static class GameEngineObjectManager s_MainObjectManager;

public:
	// constrcuter destructer
	GameEngineCore();
	~GameEngineCore();

	// delete Function
	GameEngineCore(const GameEngineCore& _Other) = delete;
	GameEngineCore(GameEngineCore&& _Other) noexcept = delete;
	GameEngineCore& operator=(const GameEngineCore& _Other) = delete;
	GameEngineCore& operator=(GameEngineCore&& _Other) noexcept = delete;

	static void EngineStart();
	static void Stop() { s_bUpdateValue = false; }
	static void RenderOut() { s_bOutValue = true; }

	static class GameEngineScreen* GetScreenPointer() { return &s_MainRender; }
	static class GameEngineObjectManager* GetObjectManagerPointer() { return &s_MainObjectManager; }

protected:

private:
	static void Loop();
	static void Release();

private:
	static bool s_bUpdateValue;
	static bool s_bOutValue;
	static float s_fStateTime;

};

