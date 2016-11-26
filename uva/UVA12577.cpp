#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i = 0;
	string str;
	while (cin >> str && str != "*")
	{
		i++;
		cout << "Case " << i << ": ";
		if (str == "Hajj")
		{
			cout << "Hajj-e-Akbar" << endl;
		}
		else
		{
			cout << "Hajj-e-Asghar" << endl;
		}
	}
	return 0;
}