#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int avail[10];
int pos[5];

int main()
{
	int N;
	int n, r1, r2;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int total = 0;
		int digit = 0;
		int cpAvail[10];
		int curr = 0;
		int ctr = 1;
		cin >> n >> r1 >> r2;
		for (int j = 0; j < 10; j++)
		{
			avail[j] = 0;
		}
		while (n > 0)
		{
			pos[digit] = n % 10;
			avail[n % 10]++;
			n /= 10;
			curr = curr * 10 + 1;
			digit++;
		}
		for (int j = 0; j < pow(9, digit); j++)
		{
			int sj;
			int g1 = 0;
			int g2 = 0;
			int cpCurr = curr;
			copy(avail, avail + 10, cpAvail);
			for (int k = 0; k < digit; k++)
			{
				sj = cpCurr % 10;
				if (pos[k] == sj)
				{
					g1++;
					cpAvail[sj]--;
					if (cpAvail[sj] < 0)
					{
						cpAvail[sj]++;
						g2--;
					}
				}
				else if (cpAvail[sj] > 0)
				{
					g2++;
					cpAvail[sj]--;
				}
				cpCurr /= 10;
			}
			if (r1 == g1 && r2 == g2)
			{
				total++;
			}
			if (ctr % 6561 == 0)
			{
				curr += 1112;
			}
			else if (ctr % 729 == 0)
			{
				curr += 112;
			}
			else if (ctr % 81 == 0)
			{
				curr += 12;
			}
			else if (ctr % 9 == 0)
			{
				curr += 2;
			}
			else
			{
				curr += 1;
			}
			ctr++;
		}
		cout << total << endl;
	}
	return 0;
}