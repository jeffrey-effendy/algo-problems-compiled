#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int from, to;
	while (cin >> from >> to && !(from == -1 && to == -1))
	{
		int n = abs(to - from);
		cout << (n < 100 - n ? n : 100 - n) << endl;
	}
	return 0;
}