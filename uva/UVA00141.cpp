#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int board[2501];
int s;
map<string, bool> memo;
map<int, bool> lenMemo;

int main()
{
    int N, n, i, j;
    while(cin >> N && N != 0)
    {
        int done = -2;
        memo.clear();
        lenMemo.clear();
        s = N;
        n = 0;
        for (i = 0; i < N * N; i++)
        {
            board[i] = 0;
        }
        for (i = 0; i < 2 * N; i++)
        {
            char sign;
            int x, y;
            cin >> x >> y >> sign;
            if (done != -2) {
                continue;
            }
            string comp;
            x--;
            y--;
            if (sign == '+')
            {
                board[s * y + x] = 1;
                n++;
            }
            else
            {
                board[s * y + x] = 0;
                n--;
            }
            if (!lenMemo[n])
            {
                lenMemo[n] = true;
                comp = "";
                for (j = 0; j < s * s; j++)
                {
                    comp += board[j] + '0';
                }
                memo[comp] = true;
                continue;
            }
            if (done == -2)
            {
                comp = "";
                for (j = 0; j < s * s; j++)
                {
                    comp += board[s * (s - 1 -  (j % s)) + (int)(j / s)] + '0';
                }                
                if (memo[comp])
                {
                    done = -3;
                }
            }
            if (done == -2)
            {
                comp = "";
                for (j = 0; j < s * s; j++)
                {
                    comp += board[s * (s - 1 -  (int)(j / s)) + s - 1 - (j % s)] + '0';
                }
                if (memo[comp])
                {
                    done = -3;
                }
            }
            if (done == -2)
            {
                comp = "";
                for (j = 0; j < s * s; j++)
                {
                    comp += board[s * (j % s) + s - 1 - (int)(j / s)] + '0';
                }
                if (memo[comp])
                {
                    done = -3;
                }
            }
            if (done == -2)
            {
                comp = "";
                for (j = 0; j < s * s; j++)
                {
                    comp += board[j] + '0';
                }
                if (memo[comp])
                {
                    done = -3;
                }
            }
            if (done == -2)
            {
                memo[comp] = true;
            }
            else if (done == -3)
            {
                done = i;
            }
        }
        if (done < 0)
        {
            cout << "Draw" << endl;
        }
        else
        {
            cout << "Player " << ((done + 1) % 2) + 1 << " wins on move " << done + 1 << endl;
        }
    }   
    return 0; 
}