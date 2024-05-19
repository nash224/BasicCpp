#pragma once

// Ό³Έν :
class GameEngineRandom
{
public:
	// constrcuter destructer
	GameEngineRandom();
	~GameEngineRandom();

	// delete Function
	GameEngineRandom(const GameEngineRandom& _Other) = delete;
	GameEngineRandom(GameEngineRandom&& _Other) noexcept = delete;
	GameEngineRandom& operator=(const GameEngineRandom& _Other) = delete;
	GameEngineRandom& operator=(GameEngineRandom&& _Other) noexcept = delete;

public:
	int RandomInt(int _Min, int _Max);
	inline void SetSeed(std::uint64_t _Seed) { MtGen = std::mt19937_64(_Seed); }

protected:

private:
	std::mt19937_64 MtGen = std::mt19937_64(time(nullptr));

};

