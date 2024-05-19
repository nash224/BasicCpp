#pragma once

// Ό³Έν :
class UI_ConsoleMessage : public GameEngineObject
{
public:
	static std::shared_ptr<class UI_ConsoleMessage> CreateConsoleMsg(int2 _Pos, const std::wstring& _wStr);

public:
	// constrcuter destructer
	UI_ConsoleMessage();
	~UI_ConsoleMessage();

	// delete Function
	UI_ConsoleMessage(const UI_ConsoleMessage& _Other) = delete;
	UI_ConsoleMessage(UI_ConsoleMessage&& _Other) noexcept = delete;
	UI_ConsoleMessage& operator=(const UI_ConsoleMessage& _Other) = delete;
	UI_ConsoleMessage& operator=(UI_ConsoleMessage&& _Other) noexcept = delete;


	void Print(const std::wstring& _wStr);

protected:

private:


};

