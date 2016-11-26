#include <iostream>

using namespace std;

int main()
{
	int K, N, M, n, m;
	while (cin >> K && K != 0)
	{
		cin >> N >> M;
		for (int i = 0; i < K; i++)
		{
			cin >> n >> m;
			if (n == N || m == M)
			{
				cout << "divisa" << endl;
			}
			else if (n < N)
			{
				if (m < M)
				{
					cout << "SO" << endl;
				}
				else
				{
					cout << "NO" << endl;
				}
			}
			else
			{
				if (m < M)
				{
					cout << "SE" << endl;
				}
				else
				{
					cout << "NE" << endl;
				}
			}
		}
	}
	return 0;
}