#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	string str;
	int a;
	int bal = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		if (str == "donate")
		{
			cin >> a;
			bal += a;
		}
		else
		{
			cout << bal << endl;
		}
	}
	return 0;
}