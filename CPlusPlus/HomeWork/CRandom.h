#pragma once
#include <random>

namespace Engine
{
	// Ό³Έν :
	class CRandom
	{
	public:
		// constrcuter destructer
		CRandom();
		~CRandom();

		// delete Function
		CRandom(const CRandom& _Other) = delete;
		CRandom(CRandom&& _Other) noexcept = delete;
		CRandom& operator=(const CRandom& _Other) = delete;
		CRandom& operator=(CRandom&& _Other) noexcept = delete;

		int RandomInt(int _Min, int _Max);
		inline void SetSeed(std::uint64_t _Seed) { MtGen = std::mt19937_64(_Seed); }

	protected:

	private:
		std::mt19937_64 MtGen = std::mt19937_64(time(nullptr));

	};

}