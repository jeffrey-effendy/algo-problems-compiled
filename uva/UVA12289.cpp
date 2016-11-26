#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	string str;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		if (str.length() == 5)
		{
			cout << 3 << endl;
		}
		else
		{
			int oneFlag = 0;
			if (str[0] == 'o')
			{
				oneFlag++;
			}
			if (str[1] == 'n')
			{
				oneFlag++;
			}
			if (str[2] == 'e')
			{
				oneFlag++;
			}
			if (oneFlag >= 2)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 2 << endl;
			}
		}
	}
	return 0;
}