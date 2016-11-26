#include <iostream>
#include <string>

using namespace std;

bool memo[11];

int main()
{
    bool restart = true;
    int guess;
    string response;
    while (true)
    {
        if (restart)
        {
            restart = false;
            for (int i = 0; i <= 10; i++)
            {
                memo[i] = true;
            }
        }
        cin >> guess;
        if (guess == 0)
        {
            break;
        }
        cin >> response >> response;
        switch (response[0])
        {
            case 'h':
                for (int i = guess; i <= 10; i++)
                {
                    memo[i] = false;
                }
                break;
            case 'l':
                for (int i = 0; i <= guess; i++)
                {
                    memo[i] = false;
                }
                break;
            case 'o':
                if (memo[guess])
                {
                    cout << "Stan may be honest" << endl;
                }
                else
                {
                    cout << "Stan is dishonest" << endl;
                }
                restart = true;
                break;
        }
    }
    return 0;
}