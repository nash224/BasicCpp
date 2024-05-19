#pragma once
#include "GameEngineObject.h"

// Ό³Έν :
class Player : public GameEngineObject
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void Start() override;
	void Update(float _DeltaTime) override;

	void Init();

	void SetPlayerNumber(std::uint32_t _iNumber) { mPlayerNumber = _iNumber; }

	void Reflect(std::uint32_t _iNumber);
	void PrintBingoCount();

	std::shared_ptr<class Bingo> GetBoardPointer() const { return mpBingoBoard; };
	std::uint32_t GetPlayerNumber() const { return mPlayerNumber; }

protected:

private:
	std::shared_ptr<class UI_ConsoleMessage> CreateConsoleMsg(int2 _Pos, const std::wstring& _wStr);

private:
	std::shared_ptr<class Bingo> mpBingoBoard;
	std::list<std::shared_ptr<class UI_ConsoleMessage>> MessageList;

	std::uint32_t mPlayerNumber = 0;

};

