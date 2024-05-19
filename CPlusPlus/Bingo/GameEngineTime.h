#pragma once

// Ό³Έν :
class GameEngineTime
{
	typedef std::chrono::system_clock::time_point TimePoint;

public:
	// constrcuter destructer
	GameEngineTime();
	~GameEngineTime();

	// delete Function
	GameEngineTime(const GameEngineTime& _Other) = delete;
	GameEngineTime(GameEngineTime&& _Other) noexcept = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(GameEngineTime&& _Other) noexcept = delete;
	
	void Update();
	float GetDeltaTime() const;

protected:

private:
	TimePoint CurTime;
	TimePoint PrevTime;
	double DoubleTime = 0.0;
	float DeltaTime = 0.0f;

};