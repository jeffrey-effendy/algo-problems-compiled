#include <iostream>

using namespace std;

int map[55][55];
int cost[55][55];
int val[55][55];

int main()
{
    int m, n;
    int wc;
    int p, px, py, pv, pc;
    int bx, by, bd, bl;
    int sum = 0;
    cin >> m >> n;
    cin >> wc;
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (j <= m)
        {
            map[i][j] = -1;
            cost[i][j] = wc;
            if (i == 1 || i == n || j == m)
            {
                j++;
            }
            else
            {
                j = m;
            }
        }
    }
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> px >> py >> pv >> pc;
        map[py][px] = 1;
        val[py][px] = pv;
        cost[py][px] = pc;
    }
    while (cin >> bx >> by >> bd >> bl)
    {
        int score = 0;
        while (bl > 0)
        {
            bl--;
            if (bl <= 0)
            {
                break;
            }
            switch (bd)
            {
                case 0:
                    if (map[by][bx+1] == 0)
                    {
                        bx++;
                    }
                    else
                    {
                        bl -= cost[by][bx+1];
                        if (map[by][bx+1] == 1)
                        {
                            score += val[by][bx+1];
                        }
                        bd = bd == 0 ? 3 : bd - 1;
                    }
                    break;
                case 1:
                    if (map[by+1][bx] == 0)
                    {
                        by++;
                    }
                    else
                    {
                        bl -= cost[by+1][bx];
                        if (map[by+1][bx] == 1)
                        {
                            score += val[by+1][bx];
                        }
                        bd = bd == 0 ? 3 : bd - 1;
                    }
                    break;
                case 2:
                    if (map[by][bx-1] == 0)
                    {
                        bx--;
                    }
                    else
                    {
                        bl -= cost[by][bx-1];
                        if (map[by][bx-1] == 1)
                        {
                            score += val[by][bx-1];
                        }
                        bd = bd == 0 ? 3 : bd - 1;
                    }
                    break;
                case 3:
                    if (map[by-1][bx] == 0)
                    {
                        by--;
                    }
                    else
                    {
                        bl -= cost[by-1][bx];
                        if (map[by-1][bx] == 1)
                        {
                            score += val[by-1][bx];
                        }
                        bd = bd == 0 ? 3 : bd - 1;
                    }
                    break;
            }
        }
        cout << score << endl;
        sum += score;
    }
    cout << sum << endl;
    return 0;
}