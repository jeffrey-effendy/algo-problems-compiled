#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Board2
{
    private:
        vector<T> _board;
    
    public:
        int col;
        int row;

        Board2(int c, int r, vector<T> board)
        {
            col = c;
            row = r;
            _board.swap(board);
        }

        T getval(int c, int r) const
        {
            if (c < 0 || r < 0 || c >= col || r >= row) return 0;
            return _board[row * r + c];
        }
};

string convertStr(string str)
{
    string out = "";
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch >= 97 && ch <= 122) out += ch;
    }
    return out;
}

int main()
{
    int T;
    string str;
    cin >> T;
    cin.ignore(80, '\n');
    for (int i = 0; i < T; i++)
    {
        getline(cin, str);
        bool flag = true;
        string mstr = convertStr(str);
        int msize = sqrt(mstr.size());
        if (msize * msize != mstr.size()) flag = false;
        if (flag)
        {
            vector<char> vstr(mstr.begin(), mstr.end());
            Board2<char> board(msize, msize, vstr);
            
            for (int j = 0; j < msize; j++)
            {
                string sstr1 = "";
                string sstr2 = "";
                string sstr3 = "";
                string sstr4 = "";
                for (int k = 0; k < msize; k++)
                {
                    int c1 = k, r1 = j;
                    int c2 = j, r2 = k;
                    int c3 = msize - k - 1, r3 = msize - j - 1;
                    int c4 = msize - j - 1, r4 = msize - k - 1;
                    sstr1 += board.getval(c1, r1);
                    sstr2 += board.getval(c2, r2);
                    sstr3 += board.getval(c3, r3);
                    sstr4 += board.getval(c4, r4);
                }
                if (strcmp(sstr1.c_str(), sstr2.c_str()) != 0 || strcmp(sstr2.c_str(), sstr3.c_str()) != 0 || strcmp(sstr3.c_str(), sstr4.c_str()) != 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        cout << "Case #" << i + 1 << ":" << endl;
        if (flag) cout << msize << endl;
        else cout << "No magic :(" << endl;
    }
    return 0;
}