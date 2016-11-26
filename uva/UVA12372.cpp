#include <iostream>

using namespace std;

int main()
{
	int T;
	int l, w, h;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> l >> w >> h;
		cout << "Case " << i + 1 << ": ";
		if (l > 20 || w > 20 || h > 20)
		{
			cout << "bad" << endl;
		}
		else
		{
			cout << "good" << endl;
		}
	}
	return 0;
}