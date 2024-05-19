#pragma once
#include "GameEngineObject.h"

// Ό³Έν :
class Bingo : public GameEngineObject
{
	static constexpr std::uint32_t WIDTH  = 5;
	static constexpr std::uint32_t HEIGHT = 5;
	static constexpr std::uint32_t BOARD_SIZE = WIDTH * HEIGHT;
	static constexpr std::uint32_t SWAP_COUNT = 1000;

public:
	// constrcuter destructer
	Bingo();
	~Bingo();

	// delete Function
	Bingo(const Bingo& _Other) = delete;
	Bingo(Bingo&& _Other) noexcept = delete;
	Bingo& operator=(const Bingo& _Other) = delete;
	Bingo& operator=(Bingo&& _Other) noexcept = delete;

	void BoardRender();
	void Reflect(std::uint32_t _Number);

	int GetBingoCount() const;

	std::uint32_t GetBoardSize() const { return BOARD_SIZE; };

protected:

private:
	void AllSwap(std::uint32_t _iSwapCount);
	std::uint8_t* FindAddress(std::uint32_t _Number);

	void BingoUpdate();
	

private:
	std::vector<std::uint8_t> Board;
	std::vector<std::vector<wchar_t>> Renderer;
	std::uint32_t mBingoCount = 0;

};

