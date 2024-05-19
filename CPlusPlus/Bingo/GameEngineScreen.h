#pragma once

// Ό³Έν :
class GameEngineScreen
{
	friend class GameEngineCore;

public:
	void CreateBuffer(std::uint32_t _Width, std::uint32_t _Height);
	void ChangeBuffer(std::uint32_t _Width, std::uint32_t _Height, wchar_t _wChar);
	void BufferUpdate(std::uint32_t _Width, std::uint32_t _Height);
	bool IsOverBuffer(std::uint32_t _Width, std::uint32_t _Height);

	void Render();
	void Clear();
	void Release();

protected:

private:
	// constrcuter destructer
	GameEngineScreen();
	~GameEngineScreen();

	// delete Function
	GameEngineScreen(const GameEngineScreen& _Other) = delete;
	GameEngineScreen(GameEngineScreen&& _Other) noexcept = delete;
	GameEngineScreen& operator=(const GameEngineScreen& _Other) = delete;
	GameEngineScreen& operator=(GameEngineScreen&& _Other) noexcept = delete;

private:
	std::vector<std::vector<wchar_t>> Buffer;

};

