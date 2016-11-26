#include <iostream>

using namespace std;

int main()
{
	int k, n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		cout << abs(((315 * n + 36962) / 10) % 10) << endl;
	}
	return 0;
}