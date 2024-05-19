#include "PreCompile.h"
#include "Bingo.h"

#include "GameEngineRandom.h"
#include <string>

#define STAR 0

Bingo::Bingo() 
{
	Board.resize(BOARD_SIZE);

	for (std::uint32_t i = 0; i < BOARD_SIZE; i++)
	{
		Board[i] = i + 1;
	}

	AllSwap(SWAP_COUNT);
}

Bingo::~Bingo() 
{
}

void Bingo::Reflect(std::uint32_t _Number)
{
	std::uint8_t* pAddress = FindAddress(_Number);
	if (nullptr == pAddress)
	{
		MsgBoxAssert("숫자에 부합한 주소가 존재하지 않습니다.");
		return;
	}

	(*pAddress) = STAR;

	BingoUpdate();
	BoardRender();
}

int Bingo::GetBingoCount() const
{
	return mBingoCount;
}

std::uint8_t* Bingo::FindAddress(std::uint32_t _Number)
{
	for (std::uint32_t  i = 0; i < BOARD_SIZE; i++)
	{
		std::uint32_t CurNumber = Board[i];
		if (_Number == CurNumber)
		{
			return &Board[i];
		}
	}

	return nullptr;
}

void Bingo::AllSwap(std::uint32_t _iSwapCount)
{
	const std::uint32_t Size = static_cast<std::uint32_t>(Board.size());

	GameEngineRandom NewRandom;
	std::uint64_t Seed = reinterpret_cast<std::uint64_t>(this);

	for (std::uint32_t i = 0; i < SWAP_COUNT; i++)
	{
		std::uint32_t Num1 = 0;
		std::uint32_t Num2 = 0;

		NewRandom.SetSeed(Seed++);
		Num1 = NewRandom.RandomInt(0, Size - 1);
		NewRandom.SetSeed(Seed++);
		Num2 = NewRandom.RandomInt(0, Size - 1);

		while (Num1 == Num2)
		{
			NewRandom.SetSeed(Seed++);
			Num2 = NewRandom.RandomInt(0, Size - 1);
		}

		std::swap(Board.at(Num1), Board.at(Num2));
	}
}

void Bingo::BingoUpdate()
{
	std::uint32_t BingoCount = 0;
	std::vector<std::uint32_t> Row(HEIGHT);
	std::vector<std::uint32_t> Col(WIDTH);
	std::vector<std::uint32_t> Dia(2);

	for (std::uint32_t y = 0; y < HEIGHT; y++)
	{
		Row[y] = 0;
	}

	for (std::uint32_t i = 0; i < BOARD_SIZE; i++)
	{
		if (STAR == Board[i])
		{
			Row[i / HEIGHT] += 1;
			Col[i % WIDTH] += 1;

			enum DiaType : uint8_t
			{
				ReverseSlash = 0,
				Slash = 1,
			};

			const std::uint32_t CurCol = (i / WIDTH);
			const std::uint32_t RS     = (CurCol * WIDTH) + CurCol;
			const std::uint32_t S      = (CurCol * WIDTH) + WIDTH - CurCol - 1;

			if (RS == i)
			{
				Dia[ReverseSlash] += 1;
			}

			if (S == i)
			{
				Dia[Slash] += 1;
			}
		}
	}

	for (std::uint32_t Num : Row)
	{
		if (WIDTH == Num)
		{
			++BingoCount;
		}
	}
	for (std::uint32_t Num : Col)
	{
		if (WIDTH == Num)
		{
			++BingoCount;
		}
	}
	for (std::uint32_t Num : Dia)
	{
		if (WIDTH == Num)
		{
			++BingoCount;
		}
	}

	mBingoCount = BingoCount;
}

void Bingo::BoardRender()
{
	if (Renderer.empty())
	{
		Renderer.resize(HEIGHT);
		for (std::uint32_t y = 0; y < HEIGHT; y++)
		{
			const std::uint32_t XSize = WIDTH * 3;
			Renderer[y].resize(XSize);

			for (std::uint32_t x = 0; x < XSize; x++)
			{
				Renderer[y][x] = L' ';
			}
		}
	}

	for (std::uint32_t i = 0; i < BOARD_SIZE; i++)
	{
		std::uint32_t y = i / HEIGHT;
		std::uint32_t x = (i % WIDTH) * 3;

		std::uint8_t Num      = Board[i];
		std::uint32_t One     = Num % 10;
		std::uint32_t Ten     = Num / 10;
		std::wstring Num_wStr = std::to_wstring(Num);
		std::vector<wchar_t> v(Num_wStr.begin(), Num_wStr.end());

		for (std::uint32_t i = 0; i < static_cast<std::uint32_t>(v.size()); i++)
		{
			Renderer[y][x + i] = v[i];
		}
		
		if (Num < 10)
		{
			Renderer[y][x + 1] = L' ';
		}

		if (STAR == Num)
		{
			Renderer[y][x] = L'*';
		}
	}

	Render(Renderer);
}
