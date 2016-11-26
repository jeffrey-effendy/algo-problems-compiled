#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const string key[] = { "`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./" };
	string in;
	while (getline(cin, in))
	{
		string out = "";
		for (int i = 0; i < in.size(); i++)
		{
			bool found = false;
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < key[j].size(); k++)
				{
					if (key[j][k] == in[i])
					{
						found = true;
						out += key[j][k - 1];
						break;
					}
				}
				if (found)
				{
					break;
				}
			}
			if (!found)
			{
				out += in[i];
			}
		}
		cout << out << endl;
	}
	return 0;
}