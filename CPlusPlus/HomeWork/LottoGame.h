#pragma once
#include <list>

namespace LottoGame
{
	typedef std::uint8_t uDataType;

	class Lotto
	{
	private:
		static constexpr int MAX_NUMBER = 45;
		static constexpr int DRAW_NUMBER = 6;

	public:
		Lotto();
		~Lotto();

		void Raffle();
		void Print();

	private:
		int DrawNumber();
		bool IsDraw(int _Number);


	private:
		std::list<uDataType> DrawNumberList;

	};

	void Excute(int _iLoopCount = 1);
}