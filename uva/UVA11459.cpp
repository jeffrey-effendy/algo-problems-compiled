#include <iostream>

using namespace std;

int players[1000000];
int shortcut[101];

int main()
{
    int T;
    int a, b, c;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int entry, exit, die;
        bool end = false;
        for (int j = 0; j < 101; j++)
        {
            shortcut[j] = 0;
        }
        cin >> a >> b >> c;
        for (int j = 0; j < b; j++)
        {
            cin >> entry >> exit;
            shortcut[entry] = exit;
        }
        for (int j = 0; j < c; j++)
        {
            if (j < a)
            {
                players[j] = 1;
            }
            cin >> die;
            if (!end)
            {
                players[j % a] += die;
                if (players[j % a] >= 100)
                {
                    end = true;
                    continue;
                }
                if (shortcut[players[j % a]] != 0)
                {
                    players[j % a] = shortcut[players[j % a]];
                }
                if (players[j % a] >= 100)
                {
                    end = true;
                }
            }
        }
        for (int j = 0; j < a; j++)
        {
            if (players[j] == 0)
            {
                players[j] = 1;
            }
            else if (players[j] > 100)
            {
                players[j] = 100;
            }
            cout << "Position of player " << j + 1 << " is " << players[j] << "." << endl;
        }
    }
    return 0;
}