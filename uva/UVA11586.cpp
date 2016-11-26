#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	cin.ignore(80, '\n');
	for (int i = 0; i < T; i++)
	{
		int m = 0, f = 0;
		string str;
		getline(cin, str);
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == 'M')
			{
				m++;
			}
			else if (str[j] == 'F')
			{
				f++;
			}
		}
		if (m == f && m > 1)
		{
			cout << "LOOP" << endl;
		}
		else
		{
			cout << "NO LOOP" << endl;
		}
	}
	return 0;
}