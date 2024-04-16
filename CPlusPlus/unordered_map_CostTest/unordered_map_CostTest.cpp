// unordered_map_CostTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <unordered_map>
#include <chrono>

class TimeMeasurement
{
public:
	void StartTimer();
	void EndTimer();

private:

	void PrintMicroSec() const;
	void PrintMilliSec() const;

private:
	std::chrono::steady_clock::time_point Start;
	std::chrono::steady_clock::time_point Stop;

};

void TimeMeasurement::StartTimer()
{
	Start = std::chrono::high_resolution_clock::now();
}

void TimeMeasurement::EndTimer()
{
	Stop = std::chrono::high_resolution_clock::now();

	PrintMicroSec();
	PrintMilliSec();
}

void TimeMeasurement::PrintMicroSec() const
{
	auto Duration = std::chrono::duration_cast<std::chrono::microseconds>(Stop - Start);
	std::cout << "Time taken by function: " << Duration.count() << " microseconds" << std::endl;
}

void TimeMeasurement::PrintMilliSec() const
{
	auto Duration = std::chrono::duration_cast<std::chrono::milliseconds>(Stop - Start);
	std::cout << "Time taken by function: " << Duration.count() << " milliseconds" << std::endl;
}

enum class Status
{
	None,
	One,
	Two,
	Three,
};

enum class StatusFlag
{
	None = 0,
	One = (1<<0),
	Two = (1 << 1),
	Three = (1 << 2),
};

namespace std
{
	template<>
	class std::hash<Status>
	{
	public:
		int operator()(Status _Type) const
		{
			return static_cast<int>(_Type);
		}
	};

}

class MyUmap
{
public:
	void AddIndex(Status _Type, StatusFlag _Index);
	StatusFlag FindIndex(Status _Type);

public:
	std::unordered_map<Status, StatusFlag> StatusIndex;

};

class MyValue
{
public:
	bool GetValue() const
	{
		return IsHit;
	}

private:
	bool IsHit = false;
	bool IsDeath = false;


};

void MyUmap::AddIndex(Status _Type, StatusFlag _Index)
{
	StatusIndex.insert(std::make_pair(_Type, _Index));
}

StatusFlag MyUmap::FindIndex(Status _Type)
{
	std::unordered_map<Status, StatusFlag>::const_iterator FindIter = StatusIndex.find(_Type); 
	if (FindIter != StatusIndex.end())
	{
		return FindIter->second;
	}

	return StatusFlag::None;
}


int main()
{
	MyUmap Umap;
	Umap.AddIndex(Status::One, StatusFlag::One);
	Umap.AddIndex(Status::Two, StatusFlag::Two);
	Umap.AddIndex(Status::Three, StatusFlag::Three);

	TimeMeasurement TM;

	TM.StartTimer();
	for (int i = 0; i < 10000; i++)
	{
		StatusFlag Flag1 = Umap.FindIndex(Status::One);
		StatusFlag Flag2 = Umap.FindIndex(Status::Two);
		StatusFlag Flag3 = Umap.FindIndex(Status::Three);
		int a = 0;
	}
	
	TM.EndTimer();

	MyValue Value;

	TM.StartTimer();
	for (int i = 0; i < 10000; i++)
	{
		Value.GetValue();
	}
	
	TM.EndTimer();

}
