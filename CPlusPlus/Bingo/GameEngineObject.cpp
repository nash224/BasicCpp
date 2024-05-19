#include "PreCompile.h"
#include "GameEngineObject.h"

#include "GameEngineCore.h"
#include "GameEngineScreen.h"

GameEngineObject::GameEngineObject() 
{
}

GameEngineObject::~GameEngineObject() 
{
}

void GameEngineObject::SetPosition(std::int32_t _x, std::int32_t _y)
{
	XPos = _x;
	YPos = _y;
}

void GameEngineObject::SetPosition(int2 _Pos)
{
	XPos = _Pos.X;
	YPos = _Pos.Y;
}

void GameEngineObject::Render(int _x, int _y, wchar_t _wchar) const
{
	GameEngineScreen* pScreen = GameEngineCore::GetScreenPointer();
	if (nullptr == pScreen)
	{
		MsgBoxAssert(L"포인터가 존재하지 않습니다.");
		return;
	}

	pScreen->ChangeBuffer(_x, _y, _wchar);
}

void GameEngineObject::Render(const std::wstring& _wStr)
{
	std::vector<std::vector<wchar_t>> v;
	v.resize(1);

	std::copy(_wStr.begin(), _wStr.end(), std::back_inserter(v[0]));
	Render(v);
}

void GameEngineObject::Render(const std::vector<std::vector<wchar_t>>& _pwchar) const
{
	if (_pwchar.empty())
	{
		MsgBoxAssert("존재하지 않는 버퍼를 스크린에 띄우려 했습니다");
		return;
	}

	const std::uint32_t YSize = static_cast<std::uint32_t>(_pwchar.size());
	const std::uint32_t XSize = static_cast<std::uint32_t>(_pwchar[0].size());

	for (std::uint32_t y = 0; y < YSize; y++)
	{
		for (std::uint32_t x = 0; x < XSize; x++)
		{
			Render(x + XPos, y + YPos, _pwchar[y][x]);
		}
	}
}
