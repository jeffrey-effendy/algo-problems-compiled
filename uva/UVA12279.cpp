#include <iostream>

using namespace std;

int main()
{
	int N;
	int e;
	int i = 0;
	while (cin >> N && N != 0)
	{
		i++;
		int bal = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> e;
			if (e > 0)
			{
				bal++;
			}
			else
			{
				bal--;
			}
		}
		cout << "Case " << i << ": ";
		cout << bal << endl;
	}
	return 0;
}