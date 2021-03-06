#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int T;
	int m, n;
	char piece;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> piece >> m >> n;
		if (piece == 'K')
		{
			cout << ceil(m / 2.0) * ceil(n/ 2.0) << endl;
		}
		else if (piece == 'k')
		{
			cout << ceil((m * n) / 2.0) << endl;
		}
		else
		{
			cout << min(m, n) << endl;
		}
	}
	return 0;
}