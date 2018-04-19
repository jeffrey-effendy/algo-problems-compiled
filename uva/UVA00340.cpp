#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int memdigit[10];
	int copymemdigit[10];
	int mempos[1001];
	int N, n, weak, strong, I = 1;
	bool allZeros;
	while (cin >> N && !(N == 0))
	{
		allZeros = true;
		for (int i = 0; i < 1001; i++)
		{
			if (i < 10)
			{
				memdigit[i] = 0;
			}
			mempos[i] = 0;
		}
		for (int i = 0; i < N; i++)
		{
			cin >> n;
			memdigit[n]++;
			mempos[i] = n;
			if (n != 0)
			{
				allZeros = false;
			}
		}
		cout << "Game " << I++ << ":" << endl;
		while (!allZeros)
		{
			allZeros = true;
			weak = 0;
			strong = 0;
			copy(memdigit, memdigit + 10, copymemdigit);
			for (int i = 0; i < N; i++)
			{
				cin >> n;
				if (n != 0)
				{
					allZeros = false;
				}
				if (mempos[i] == n)
				{
					strong++;
					copymemdigit[n]--;
					if (copymemdigit[n] < 0)
					{
						weak--;
						copymemdigit[n] = 0;
					}
				}
				else if (copymemdigit[n] > 0)
				{
					weak++;
					copymemdigit[n]--;
				}
			}
			if (!allZeros)
			{
				cout << "    (" << strong << "," << weak << ")" << endl;
			}
		}
	}
	return 0;
}