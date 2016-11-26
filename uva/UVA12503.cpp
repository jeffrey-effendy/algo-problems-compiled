#include <iostream>

using namespace std;

int main()
{
	int T, n, pos;
	string str;
	int move[101];
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		pos = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> str;
			if (str == "LEFT")
			{
				move[j] = -1;
			}
			else if (str == "RIGHT")
			{
				move[j] = 1;
			}
			else
			{
				int same;
				cin >> str >> same;
				move[j] = move[same - 1];
			}
			pos += move[j];
		}
		cout << pos << endl;
	}
	return 0;
}