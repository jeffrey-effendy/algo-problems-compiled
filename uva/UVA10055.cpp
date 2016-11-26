#include <iostream>

using namespace std;

int main()
{
	long long i, j;
	while (cin >> i >> j)
	{
		if (i < j)
			cout << j - i << endl;
		else
			cout << i - j << endl;
	}
	return 0;
}