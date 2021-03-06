#include <iostream>

using namespace std;

int f(int n)
{
	int temp = n;
	int sum = 0;
	while (temp != 0)
	{
		sum += temp % 10;
		temp /= 10;
	}
	return sum;
}

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		int prevRes = 0, res;
		res = f(n);
		while (res != prevRes)
		{
			prevRes = res;
			res = f(res);
		}
		cout << res << endl;
	}
	return 0;
}