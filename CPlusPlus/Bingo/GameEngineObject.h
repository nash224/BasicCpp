#pragma once

// 설명 :
class GameEngineObject : public std::enable_shared_from_this<GameEngineObject>
{
	friend class GameEngineObjectManager;

public:
	// constrcuter destructer
	GameEngineObject();
	virtual ~GameEngineObject();

	// delete Function
	GameEngineObject(const GameEngineObject& _Other) = delete;
	GameEngineObject(GameEngineObject&& _Other) noexcept = delete;
	GameEngineObject& operator=(const GameEngineObject& _Other) = delete;
	GameEngineObject& operator=(GameEngineObject&& _Other) noexcept = delete;

	virtual void Start() {}
	virtual void Update(float _DeltaTime) {}

	void SetPosition(std::int32_t _x, std::int32_t _y);
	void SetPosition(int2 _Pos);
	inline int2 GetPosition() const { return int2(XPos, YPos); }

protected:
	// 화면에 단일문자를 찍을 수 있습니다.
	void Render(int _x, int _y, wchar_t _wchar) const;
	void Render(const std::wstring& _wStr);
	// Position이 지정된 위치에 vector 배열을 렌더링합니다.
	void Render(const std::vector<std::vector<wchar_t>>& _pwchar) const;

private:
	inline void SetOrder(std::int32_t _Order) { Order = _Order; }
	inline std::int32_t GetOrder() const { return Order; }

private:
	std::int32_t Order = 0;
	std::int32_t XPos = 0;
	std::int32_t YPos = 0;

};

