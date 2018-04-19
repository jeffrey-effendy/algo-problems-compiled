#include <iostream>
#include <string>

using namespace std;

void decode(string *str)
{
	for (auto i = (*str).begin(); i != (*str).end(); ++i)
	{
		cout << (char)((*i) - 7);
	}
	cout << endl;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		decode(&str);
	}
	return 0;
}