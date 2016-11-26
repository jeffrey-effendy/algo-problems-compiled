#include <iostream>
#include <string>

using namespace std;

int main()
{
	string x;
	while (cin >> x && x != "END")
	{
		int index = 0;
		string prevX = "";
		while (prevX != x)
		{
			prevX = x;
			x = to_string(x.size());
			index++;
		}
		cout << index << endl;
	}
	return 0;
}