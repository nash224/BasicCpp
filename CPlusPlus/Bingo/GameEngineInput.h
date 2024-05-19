#pragma once

// Ό³Έν :
class GameEngineInput
{
	class InputKey
	{
	public:
		InputKey()
		{
			Key = -1;
		}

		InputKey(std::uint32_t _Key)
			: Key(_Key)
		{

		}

		~InputKey()
		{

		}

	public:
		void Update();

		inline bool IsDown() const { return DownValue; }
		inline bool IsUp() const { return UpValue; }
		inline bool IsPress() const { return PressValue; }
		inline bool IsFree() const { return FreeValue; }
		
		inline bool InputCheck() const { return 0 != GetAsyncKeyState(Key); }
		void Reset()
		{
			DownValue  = false;
			UpValue    = false;
			PressValue = false;
			FreeValue  = true;
		}

	private:
		bool DownValue = false;
		bool UpValue = false;
		bool PressValue = false;
		bool FreeValue = true;

		std::uint32_t Key = -1;

	};

public:
	// constrcuter destructer
	GameEngineInput();
	~GameEngineInput();

	// delete Function
	GameEngineInput(const GameEngineInput& _Other) = delete;
	GameEngineInput(GameEngineInput&& _Other) noexcept = delete;
	GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
	GameEngineInput& operator=(GameEngineInput&& _Other) noexcept = delete;

	static void Initialize();
	static void Update();
	static void Reset();
	static void Release();

	static InputKey* FindKey(std::uint32_t _Key);
	static bool IsPress(std::uint32_t _Key);
	static bool IsFree(std::uint32_t _Key);
	static bool IsDown(std::uint32_t _Key);
	static bool IsUp(std::uint32_t _Key);

protected:

private:
	static std::map<std::uint32_t, InputKey> AllKeys;

};
