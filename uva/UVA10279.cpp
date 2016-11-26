#include <iostream>

using namespace std;

char mine[11][11];
char play[11][11];
int mineidx[121];

int main()
{
    int T, n;
    char c;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        bool mineTouched = false;
        int idx = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> c;
                mine[j][k] = c;
            }
        }
        if (i > 0)
        {
            cout << endl;
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> c;
                if (c == 'x' && mine[j][k] == '*')
                {
                    mineTouched = true;
                    for (int l = 0; l < idx; l += 2)
                    {
                        play[mineidx[l]][mineidx[l+1]] = '*';
                    }
                }
                if (!mineTouched && mine[j][k] == '*')
                {
                    mineidx[idx++] = j;
                    mineidx[idx++] = k;
                }
                if (mineTouched && mine[j][k] == '*')
                {
                    play[j][k] = '*';
                }
                else if (c == 'x')
                {
                    int mines = 0;
                    if (j != 0 && k != 0 && mine[j-1][k-1] == '*')
                    {
                        mines++;
                    }
                    if (j != 0 && mine[j-1][k] == '*')
                    {
                        mines++;
                    }
                    if (j != 0 && k != n - 1 && mine[j-1][k+1] == '*')
                    {
                        mines++;
                    }
                    if (k != 0 && mine[j][k-1] == '*')
                    {
                        mines++;
                    }
                    if (mine[j][k] == '*')
                    {
                        mines++;
                    }
                    if (k != n - 1 && mine[j][k+1] == '*')
                    {
                        mines++;
                    }                    
                    if (j != n - 1 && k != 0 && mine[j+1][k-1] == '*')
                    {
                        mines++;
                    }
                    if (j != n - 1 && mine[j+1][k] == '*')
                    {
                        mines++;
                    }
                    if (j != n - 1 && k != n - 1 && mine[j+1][k+1] == '*')
                    {
                        mines++;
                    }
                    play[j][k] = mines + '0';
                }
                else
                {
                    play[j][k] = '.';
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << play[j][k];
            }
            cout << endl;
        }
    }
    return 0;
}