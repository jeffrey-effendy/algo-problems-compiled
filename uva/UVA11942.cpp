#include <iostream>

using namespace std;

int main()
{
	int T, prevBeard, beard;
	cin >> T;
	cout << "Lumberjacks:" << endl;
	for (int i = 0; i < T; i++)
	{
		int bigger = 0, smaller = 0;
		cin >> prevBeard;
		for (int i = 1; i < 10; i++)
		{
			cin >> beard;
			if (beard > prevBeard)
			{
				bigger++;
			}
			else if (beard < prevBeard)
			{
				smaller++;
			}
			prevBeard = beard;
		}
		if (bigger == 9 || smaller == 9)
		{
			cout << "Ordered" << endl;
		}
		else
		{
			cout << "Unordered" << endl;
		}
	}
	return 0;
}