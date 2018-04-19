#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, char> reverseMemo;

int isPaliMirror(string str)
{
    int out = 3;
    bool pFlag = true;
    bool mFlag = true;
    for (int i = 0; i < (str.size() + 1) / 2; i++)
    {
        char ch = str[i];
        char rch = str[str.size() - i - 1];
        if (pFlag && ch != rch) pFlag = false;
        if (mFlag && reverseMemo[ch] != rch) mFlag = false;
        if (!pFlag && !mFlag) break;
    }
    if (!pFlag) out -= 1;
    if (!mFlag) out -= 2;
    return out;
}

int main()
{
    string str;
    reverseMemo['A'] = 'A';
    reverseMemo['E'] = '3';
    reverseMemo['H'] = 'H';
    reverseMemo['I'] = 'I';
    reverseMemo['J'] = 'L';
    reverseMemo['L'] = 'J';
    reverseMemo['M'] = 'M';
    reverseMemo['O'] = 'O';
    reverseMemo['S'] = '2';
    reverseMemo['T'] = 'T';
    reverseMemo['U'] = 'U';
    reverseMemo['V'] = 'V';
    reverseMemo['W'] = 'W';
    reverseMemo['X'] = 'X';
    reverseMemo['Y'] = 'Y';
    reverseMemo['Z'] = '5';
    reverseMemo['1'] = '1';
    reverseMemo['2'] = 'S';
    reverseMemo['3'] = 'E';
    reverseMemo['5'] = 'Z';
    reverseMemo['8'] = '8';
    while (cin >> str)
    {
        int n = isPaliMirror(str);
        switch (n)
        {
            case 1:
                cout << str << " -- is a regular palindrome." << endl;
                break;
            case 2:
                cout << str << " -- is a mirrored string." << endl;
                break;
            case 3:
                cout << str << " -- is a mirrored palindrome." << endl;
                break;
            default:
                cout << str << " -- is not a palindrome." << endl;
        }
        cout << endl;
    }
    return 0;
}