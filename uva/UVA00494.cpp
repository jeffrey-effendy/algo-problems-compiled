#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool bit;
	int count;
	string str;
	while (getline(cin, str))
	{
		bit = false;
		count = 0;
		for (auto i = (str).begin(); i != (str).end(); ++i)
		{
			if (isalpha(*i))
				bit = true;
			if (!isalpha(*i) && bit)
			{
				count++;
				bit = false;
			}			
		}
		if (bit)
			count++;
		cout << count << endl;
	}
	return 0;
}