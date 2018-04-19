#include <iostream>
#include <string>

using namespace std;

int main()
{
	int round, nalpha, nguess;
	string guess, solution;
	bool alpha[26], alphaguess[26];
	while (cin >> round && !(round == -1))
	{
		nalpha = 0;
		nguess = 0;
		for (int i = 0; i < 26; i++)
		{
			alpha[i] = false;
			alphaguess[i] = false;
		}
		cin >> solution;
		cin >> guess;
		for (int i = 0; i < solution.size(); i++)
		{
			if (!alpha[solution[i] - 'a'])
			{
				nalpha++;
			}
			alpha[solution[i] - 'a'] = true;
		}
		for (int i = 0; i < guess.size(); i++)
		{
			if (!alphaguess[guess[i] - 'a'])
			{
				if (alpha[guess[i] - 'a'])
				{
					nalpha--;
				}
				else
				{
					nguess++;
				}
			}
			alphaguess[guess[i] - 'a'] = true;
			if (nguess == 7)
			{
				break;
			}
		}
		cout << "Round " << round << endl;
		if (nalpha == 0)
		{
			cout << "You win." << endl;
		}
		else if (nguess == 7)
		{
			cout << "You lose." << endl;
		}
		else
		{
			cout << "You chickened out." << endl;
		}
	}
	return 0;
}