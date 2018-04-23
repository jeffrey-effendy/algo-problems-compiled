#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Structure: the word count of each alphabet
// Example of ABBBCCZ = [1, 3, 2, 0, ..., 0, 1]
string dictStr[2001];
int dict[2001][26];
int dictLen = 0;

vector< vector<int> > candidates;

void worker(string strPhrase, set<string> setPhrase, int phrase[], int lenPhrase, int candidateIdx, int dictIdx)
{
    if (lenPhrase == 0)
    {
        cout << strPhrase << " =";
        for (int i = 0; i < candidates[candidateIdx].size(); i++) cout << " " << dictStr[candidates[candidateIdx][i]];
        cout << endl;
        return;
    }
    if (dictIdx == dictLen) return;
    int dictLen = 0;
    int phraseCopy[26];
    bool negativeFlag = false;
    for (int i = 0; i < 26; i++)
    {
        phraseCopy[i] = phrase[i] - dict[dictIdx][i];
        dictLen += dict[dictIdx][i];
        if (phraseCopy[i] < 0)
        {
            negativeFlag = true;
            break;
        }
    }
    if (!negativeFlag && setPhrase.find(dictStr[dictIdx]) == setPhrase.end())
    {
        vector<int> newCandidate(candidates[candidateIdx]);
        newCandidate.push_back(dictIdx);
        candidates.push_back(newCandidate);
        worker(strPhrase, setPhrase, phraseCopy, lenPhrase - dictLen, candidates.size() - 1, dictIdx + 1);
    }
    worker(strPhrase, setPhrase, phrase, lenPhrase, candidateIdx, dictIdx + 1);
}

int main()
{
    string str;
    while (getline(cin, str) && str[0] != '#')
    {
        int phrase[26] = {};
        for (int i = 0; i < str.size(); i++) if (str[i] >= 65 && str[i] <= 90) phrase[str[i] - 65]++;
        copy(phrase, phrase + 26, dict[dictLen]);
        dictStr[dictLen] = str;
        dictLen++;
    }
    while (getline(cin, str) && str[0] != '#')
    {
        candidates.clear();
        candidates.push_back(vector<int>());
        set<string> setPhrase;
        int phrase[26] = {};
        int phraseLen = 0;
        string strCp = "";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 65 && str[i] <= 90)
            {
                phrase[str[i] - 65]++;
                phraseLen++;
                strCp += str[i];
            }
            else if (strCp.size() > 0)
            {
                setPhrase.insert(strCp);
                strCp = "";
            }
        }
        if (strCp.size() > 0) setPhrase.insert(strCp);
        worker(str, setPhrase, phrase, phraseLen, 0, 0);
    }
    return 0;
}