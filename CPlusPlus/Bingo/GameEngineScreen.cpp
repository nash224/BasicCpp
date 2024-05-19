#include "PreCompile.h"
#include "GameEngineScreen.h"

GameEngineScreen::GameEngineScreen() 
{
}

GameEngineScreen::~GameEngineScreen() 
{
}


void GameEngineScreen::CreateBuffer(std::uint32_t _Width, std::uint32_t _Height)
{
	Buffer.resize(_Height);

	for (std::uint32_t y = 0; y < _Height; y++)
	{
		Buffer[y].resize(_Width);

		for (std::uint32_t x = 0; x < _Width; x++)
		{
			Buffer[y][x] = L' ';
		}
	}
}

void GameEngineScreen::ChangeBuffer(std::uint32_t _Width, std::uint32_t _Height, wchar_t _wChar)
{
	if (Buffer.empty())
	{
		MsgBoxAssert("Not Empty in STL Vector");
		return;
	}


	if (true == IsOverBuffer(_Width, _Height))
	{
		const std::uint32_t xSize = static_cast<std::uint32_t>(Buffer[0].size());
		const std::uint32_t ySize = static_cast<std::uint32_t>(Buffer.size());
		std::uint32_t Width       = xSize;
		std::uint32_t Height      = ySize;

		if (ySize <= _Height)
		{
			//if (ySize * 2 <= _Height)
			//{
			//	Height = _Height + 1;
			//}
			//else
			//{
			//	Height = ySize * 2;
			//}

			Height = _Height + 1;
		}

		if (xSize <= _Width)
		{
			//if (xSize * 2 <= _Width)
			//{
			//	Width = _Width + 1;
			//}
			//else
			//{
			//	Width = xSize * 2;
			//}
			Width = _Width + 1;
		}

		BufferUpdate(Width, Height);
	}

	Buffer[_Height][_Width] = _wChar;
}

void GameEngineScreen::BufferUpdate(std::uint32_t _Width, std::uint32_t _Height)
{
	Buffer.resize(_Height);

	for (std::uint32_t i = 0; i < _Height; i++)
	{
		Buffer[i].resize(_Width, L' ');
	}
}

bool GameEngineScreen::IsOverBuffer(std::uint32_t _Width, std::uint32_t _Height)
{
	const std::uint32_t xSize = static_cast<std::uint32_t>(Buffer[0].size());
	const std::uint32_t ySize = static_cast<std::uint32_t>(Buffer.size());

	if (xSize <= _Width || ySize <= _Height)
	{
		return true;
	}
	
	return false;
}

void GameEngineScreen::Render()
{
	if (Buffer.empty())
	{
		MsgBoxAssert("Not Initial Screen");
		return;
	}

	const std::uint32_t height = static_cast<std::uint32_t>(Buffer.size());
	const std::uint32_t width  = static_cast<std::uint32_t>(Buffer[0].size());

	for (std::uint32_t y = 0; y < height; y++)
	{
		for (std::uint32_t x = 0; x < width; x++)
		{
			std::wcout << Buffer[y][x];
			// std::wcout << L"¤·";
		}

		std::wcout << std::endl;
	}
}

void GameEngineScreen::Clear()
{
	system("cls");
}

void GameEngineScreen::Release()
{
	Buffer.clear();
}
