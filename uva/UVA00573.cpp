#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int H, U, D, F;
	while (cin >> H >> U >> D >> F && H != 0)
	{
		int day = 0;
		float currentHeight = 0, speed = U;
		bool success = false, fail = false;
		while (!success & !fail)
		{
			day++;
			currentHeight += max(0.0f, speed);
			if (currentHeight > H)
			{
				success = true;
			}
			speed -= (float) U * F / 100.0;
			currentHeight -= D;
			if (currentHeight < 0)
			{
				fail = true;
			}
		}
		if (success)
		{
			cout << "success on day " << day << endl;
		}
		else
		{
			cout << "failure on day " << day << endl;
		}
	}
	return 0;
}