#include <iostream>

using namespace std;

int main()
{
	int bankReserves[21];
	int B, N;
	while (cin >> B >> N && !(B == 0 && N == 0))
	{
		for (int i = 0; i < B; i++)
		{
			cin >> bankReserves[i];
		}
		for (int i = 0; i < N; i++)
		{
			int D, C, V;
			cin >> D >> C >> V;
			bankReserves[D - 1] -= V;
			bankReserves[C - 1] += V;
		}
		bool safe = true;
		for (int i = 0; i < B;i++)
		{
			if (bankReserves[i] < 0)
			{
				safe = false;
			}
		}
		if (safe)
		{
			cout << "S" << endl;
		}
		else
		{
			cout << "N" << endl;
		}
	}	
	return 0;
}