#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> nextPali;

bool isPali(string str)
{
    return equal(str.begin(), str.end(), str.rbegin());
}

int main()
{
    string currPali = "00:00";
    for (int i = 1439; i >= 0; i--)
    {
        string _secStr = to_string(i % 60), _minStr = to_string((int) i / 60);
        string secStr = i > 59 ? string(2 - _secStr.size(), '0').append(_secStr) : _secStr, minStr = i > 59 ? _minStr : "";
        string timeStr = string(2 - minStr.size(), '0').append(minStr) + ":" + string(2 - secStr.size(), '0').append(secStr);
        nextPali[timeStr] = currPali;
        if (isPali(minStr + secStr))
        {
            currPali = timeStr;
        }
    }
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        cout << nextPali[str] << endl;
    }
    return 0;
}