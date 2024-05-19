#pragma once
#include "GameEngineObject.h"

// Ό³Έν :
class GameSet : public GameEngineObject
{
	struct GameManager
	{
	public:
		enum ERuleCode : std::uint8_t
		{
			Error = 0,
			Pass = 1,
			Duplication = 2,
		};

		void SetBuffer(std::uint32_t _iSize)
		{
			DrawNumberList.resize(_iSize, false);
		}

		ERuleCode NumberCheck(std::uint32_t _Number);

	private:
		std::vector<bool> DrawNumberList;

	};

public:
	// constrcuter destructer
	GameSet();
	~GameSet();

	// delete Function
	GameSet(const GameSet& _Other) = delete;
	GameSet(GameSet&& _Other) noexcept = delete;
	GameSet& operator=(const GameSet& _Other) = delete;
	GameSet& operator=(GameSet&& _Other) noexcept = delete;

	void Start() override;
	void Update(float _DeltaTime) override;

	void InputUpdate();
	void InputRender();

	void ReflectToPlayer(std::uint32_t _Number);
	bool DeterWinner();

	void UpdateSystemMSG(float _DeltaTime);
	void ClearSystemMsg();

protected:

private:
	std::shared_ptr<class Player> CreatePlayer(std::int32_t _PlayerNumber, int2 _Pos);
	std::shared_ptr<class UI_ConsoleMessage> CreateConsoleMsg(int2 _Pos, const std::wstring& _wStr);

private:
	std::list<std::shared_ptr<class Player>> PlayerList;
	std::list<std::shared_ptr<class UI_ConsoleMessage>> MessageList;

	GameManager mGameManager;

	std::shared_ptr<UI_ConsoleMessage> pInputMSG;
	std::wstring InputMSG;

	std::shared_ptr<UI_ConsoleMessage> pSystemMSG;

	float fStateTime = 0.0f;
};