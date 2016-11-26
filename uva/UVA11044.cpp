#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int k, n, m;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n >> m;
		cout << (int)(ceil((n - 2) / 3.0) * ceil((m - 2) / 3.0)) << endl;
	}
	return 0;
}