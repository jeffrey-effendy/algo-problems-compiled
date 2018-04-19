#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        map<string, bool> memo;
        int nPali = 0;
        for (int i = 0; i < str.size(); i++)
        {
            for (int j = 0; j < str.size() - i; j++)
            {
                string subStr = str.substr(j, i + 1);
                if (equal(subStr.begin(), subStr.end(), subStr.rbegin()) && !memo[subStr]) {
                    memo[subStr] = true;
                    nPali++;
                }
            }
        }
        cout << "The string '" << str << "' contains " << nPali << " palindromes." << endl;
    }
    return 0;
}