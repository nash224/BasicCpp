#pragma once


// Ό³Έν :
class GameEngineMath
{
public:
	// constrcuter destructer
	GameEngineMath();
	~GameEngineMath();

	// delete Function
	GameEngineMath(const GameEngineMath& _Other) = delete;
	GameEngineMath(GameEngineMath&& _Other) noexcept = delete;
	GameEngineMath& operator=(const GameEngineMath& _Other) = delete;
	GameEngineMath& operator=(GameEngineMath&& _Other) noexcept = delete;

protected:

private:


};


class int2
{
public:
	int2()
		: X(0)
		, Y(0)
	{

	}

	int2(std::int32_t _X, std::int32_t _Y)
		: X(_X)
		, Y(_Y)
	{

	}

	int2(const int2& _Other)
		: X(_Other.X)
		, Y(_Other.Y)
	{

	}

	int2 operator+(const int2& _Other)
	{
		int2 ReturnValue;
		ReturnValue.X = X + _Other.X;
		ReturnValue.Y = Y + _Other.Y;
		return ReturnValue;
	}

	int2& operator+=(const int2& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
		return *this;
	}

protected:

public:
	std::int32_t X;
	std::int32_t Y;

};