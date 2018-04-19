#include <cstring>
#include <iostream>

using namespace std;

string convertStr(string str)
{
    string out = "";
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch >= 65 && ch <= 90) ch += 32;
        if (ch >= 97 && ch <= 122) out += ch;
    }
    return out;
}

bool isPali(string str)
{
    return equal(str.begin(), str.end(), str.rbegin());
}

int main()
{
    string str;
    while (getline(cin, str) && strcmp(str.c_str(), "DONE") != 0)
    {
        if (isPali(convertStr(str))) cout << "You won't be eaten!" << endl;
        else cout << "Uh oh.." << endl;
    }
    return 0;
}