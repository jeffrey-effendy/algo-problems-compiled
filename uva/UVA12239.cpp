#include <cmath>
#include <iostream>

using namespace std;

bool bingo[100];
int balls[100];

int main()
{
    int N, B, b;
    while (cin >> N >> B && !(N == 0 && B == 0))
    {
        int possible = 0;
        for (int i = 0; i <= N; i++)
        {
            bingo[i] = false;
        }
        for (int i = 0; i < B; i++)
        {
            cin >> balls[i];
        }
        for (int i = 0; i < B; i++)
        {
            for (int j = 0; j < B; j++)
            {
                if (!bingo[abs(balls[i] - balls[j])])
                {
                    bingo[abs(balls[i] - balls[j])] = true;
                    possible++;
                }
            }
        }
        if (possible == N + 1)
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
    return 0;
}