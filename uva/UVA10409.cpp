#include <iostream>
#include <string>

using namespace std;

int main()
{
    int top;
    int up[2];
    int side[2];
    int n;
    string dir;
    while (cin >> n && n != 0)
    {
        top = 1;
        up[0] = 2; side[0] = 3;
        up[1] = 5; side[1] = 4;
        for (int i = 0; i < n; i++)
        {
            cin >> dir;
            int temp = top;
            switch (dir[0])
            {
                case 'n':
                    top = up[1];
                    up[0] = temp;
                    up[1] = 7 - temp;
                    break;
                case 's':
                    top = up[0];
                    up[0] = 7 - temp;
                    up[1] = temp;
                    break;
                case 'w':
                    top = side[1];
                    side[0] = temp;
                    side[1] = 7 - temp;
                    break;
                case 'e':
                    top = side[0];
                    side[0] = 7 - temp;
                    side[1] = temp;
                    break;
            }
        }
        cout << top << endl;
    }
}