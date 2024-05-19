#include "LottoGame.h"

#include <iostream>

#include "CRandom.h"

namespace LottoGame
{
	Engine::CRandom g_Random;
	std::uint64_t g_Seed = 0;

	Lotto::Lotto()
	{
	}

	Lotto::~Lotto()
	{

	}

	void Lotto::Raffle()
	{
		for (int i = 0; i < DRAW_NUMBER; i++)
		{
			int Number = DrawNumber();
			DrawNumberList.push_back(Number);
		}
	}

	void Lotto::Print()
	{
		if (DrawNumberList.empty())
		{
			std::cout << "추첨번호가 존재하지 않습니다." << std::endl;
			return;
		}

		for (int Number : DrawNumberList)
		{
			std::cout << Number << " ";
		}
	}

	int Lotto::DrawNumber()
	{
		int LoopCount = 0;
		int Number    = 0;

		while (LoopCount < INT16_MAX)
		{
			++g_Seed;
			g_Random.SetSeed(g_Seed);
			Number = g_Random.RandomInt(0, MAX_NUMBER);

			if (false == IsDraw(Number))
			{
				break;
			}
			
			++LoopCount;
		}

		return Number;
	}

	bool Lotto::IsDraw(int _Number)
	{
		for (int Number : DrawNumberList)
		{
			if (_Number == Number)
			{
				return true;
			}
		}

		return false;
	}

	void Excute(int _iLoopCount /*= 1*/)
	{
		std::cout << "추첨 번호를 알려드리겠습니다." << std::endl;
		std::cout << "추첨 번호는 \'" << _iLoopCount << "\'" << "회 실행됩니다." << std::endl;

		for (int i = 0; i < _iLoopCount; i++)
		{
			std::cout << i + 1 << "회 : ";

			Lotto NewGame;
			NewGame.Raffle();
			NewGame.Print();

			std::cout << std::endl;
		}
	}
}