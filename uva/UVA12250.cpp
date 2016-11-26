#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i = 0;
	string str;
	while (cin >> str && str != "#")
	{
		i++;
		cout << "Case " << i << ": ";
		if (str == "HELLO")
		{
			cout << "ENGLISH" << endl;
		}
		else if (str == "HOLA")
		{
			cout << "SPANISH" << endl;
		}
		else if (str == "HALLO")
		{
			cout << "GERMAN" << endl;
		}
		else if (str == "BONJOUR")
		{
			cout << "FRENCH" << endl;
		}
		else if (str == "CIAO")
		{
			cout << "ITALIAN" << endl;
		}
		else if (str == "ZDRAVSTVUJTE")
		{
			cout << "RUSSIAN" << endl;
		}
		else
		{
			cout << "UNKNOWN" << endl;
		}
	}
	return 0;
}