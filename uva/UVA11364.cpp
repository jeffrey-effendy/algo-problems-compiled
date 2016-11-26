#include <iostream>

using namespace std;

int main()
{
	int k, n, x;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int min = 100, max = -1;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			if (min > x)
			{
				min = x;
			}
			if (max < x)
			{
				max = x;
			}
		}
		cout << 2 * (max - min) << endl;
	}
	return 0;
}