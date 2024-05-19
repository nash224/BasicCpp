#include <bits/stdc++.h>
#include <vector>
#include "minimumBribes.h"

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int hourglassSum(vector<vector<int>> arr)
{
	const int Row = 6;
	const int Col = 6;

	int Max_Score = INT_MIN;

	for (int y = 1; y < Col - 1; y++)
	{
		for (int x = 1; x < Row - 1; x++)
		{
			int Sum = 0;

			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					Sum += arr[y + i][x + j];
				}
			}

			Sum -= (arr[y][x - 1] + arr[y][x + 1]);

			Max_Score = max(Max_Score, Sum);
		}
	}

	return Max_Score;
}

int main()
{
	std::vector<int> Vector = { 2, 1, 5 ,3 ,4 };
	MinimumBribes::minimumBribes(Vector);
}

string ltrim(const string& str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string& str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string& str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
