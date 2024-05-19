#include "Sol.h"
#include<iostream>
#include<queue>
#include <list>

// 10번의 기회
// 빨간공이 들어가면 성공 
// 파란공이 들어가면 안됨

// 방향은 상하좌우
// 구슬은 다른 구슬 또는 벽에 막히면 움직임 종료

// 순서
// 1.컨테이너
// 2.구슬 찾기
// While
// 3.분기점 (상하좌우)
// for
// 4.움직이는 결과가 같으면 분기종료
//	<< 태훈식이라면 Record 자료구조 만들것

struct step
{
	step()
	{

	}

	step(int _Rx, int _Ry, int _Bx, int _By, int _Count)
		: Rx(_Rx), Ry(_Ry), Bx(_Bx), By(_By), Count(_Count)
	{

	}

	int Rx = 0, Ry = 0;
	int Bx = 0, By = 0;
	int Count = 0;

	bool IsVisited(const step& _Other) const
	{
		if (
			Rx == _Other.Rx &&
			Ry == _Other.Ry &&
			Bx == _Other.Bx &&
			By == _Other.By
			)
		{
			return true;
		}

		return false;
	}

};


char Map[10][11];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

// 구슬별로 작동
void move(int _Dir,int* _Nx, int* _Ny)
{
	int& Nx = *_Nx;
	int& Ny = *_Ny;

	int Move_y = dy[_Dir];
	int Move_x = dx[_Dir];

	while (
		Map[Ny + Move_y][Nx + Move_x] != '#' &&
		Map[Ny][Nx] != 'O')
	{
		Ny += dy[_Dir];
		Nx += dx[_Dir];
	}
}

int BFS(step& _Startstep)
{
	std::list<step> VisitList;
	VisitList.push_back(_Startstep);

	const step& StartStep = _Startstep;
	std::queue<step> q_Step;
	q_Step.push(StartStep);

	while (false == q_Step.empty())
	{
		step CurStep = q_Step.front();
		int next_Rx = CurStep.Rx;
		int next_Ry = CurStep.Ry;
		int next_Bx = CurStep.Bx;
		int next_By = CurStep.By;
		q_Step.pop();

		

		if (CurStep.Count > 9)
		{
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			move(i, &next_Rx, &next_Ry);
			move(i, &next_Bx, &next_By);

			if (next_Bx == next_Rx && next_By == next_Ry)
			{
				int RDist = std::abs(next_Rx - CurStep.Rx) + std::abs(next_Ry - CurStep.Ry);
				int BDist = std::abs(next_Bx - CurStep.Bx) + std::abs(next_By - CurStep.By);
				if (RDist > BDist)
				{
					next_Rx -= dx[i];
					next_Ry -= dy[i];
				}
				else
				{
					next_Bx -= dx[i];
					next_By -= dy[i];
				}
			}

			if (Map[next_By][next_Bx] == 'O')
			{
				continue;
			}
			if (Map[next_Ry][next_Rx] == 'O')
			{
				return CurStep.Count + 1;
			}

			step NewStep = { next_Rx, next_Ry,next_Bx, next_By, CurStep.Count + 1 };

			bool IsVisit = false;
			for (const step& Step : VisitList)
			{
				if (true == Step.IsVisited(NewStep))
				{
					IsVisit = true;
					break;
				}
			}

			if (false == IsVisit)
			{
				VisitList.push_back(NewStep);
				q_Step.push(NewStep);
				std::cout << NewStep.Ry << NewStep.Rx << "  , Count : " << NewStep.Count << std::endl;
			}
		}
	}

	return -1;
}

void Answer()
{
	int N, M;
	std::cin >> N >> M;
	int Rx, Ry, Bx, By;
	Rx = Ry = Bx = By = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			std::cin >> Map[y][x];

			if (Map[y][x] == 'R')
			{
				Map[y][x] = '.';
				Rx = x; Ry = y;
			}
			else if (Map[y][x] == 'B')
			{
				Map[y][x] = '.';
				Bx = x; By = y;
			}
		}
	}

	step NewStep = { Rx, Ry, Bx, By, 0 };
	int Result = BFS(NewStep);
	std::cout << Result << std::endl;
}

int BeadEscape::run()
{
	Answer();
	return 0;
}
