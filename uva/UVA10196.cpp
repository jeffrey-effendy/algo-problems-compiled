#include <iostream>
#include <string>

using namespace std;

int board[8][8];

bool checkDanger(int i, int j, bool white)
{
	// check for pawn
	if (white && i - 1 >= 0 && j -1 >= 0)
	{
		if (board[i - 1][j - 1] == 'p')
		{
			return true;
		}
	}
	if (white && i - 1 >= 0 && j + 1 <= 7)
	{
		if (board[i - 1][j + 1] == 'p')
		{
			return true;
		}
	}
	if (!white && i + 1 <= 7 && j - 1 >= 0)
	{
		if (board[i + 1][j - 1] == 'P')
		{
			return true;
		}
	}
	if (!white && i + 1 <= 7 && j + 1 <= 7)
	{
		if (board[i + 1][j + 1] == 'P')
		{
			return true;
		}
	}

	// check horse
	if (i - 1 >= 0 && j - 2 >= 0)
	{
		int enemy = white ? 'n' : 'N';
		if (board[i - 1][j - 2] == enemy)
		{
			return true;
		}
	}
	if (i - 1 >= 0 && j + 2 <= 7)
	{
		int enemy = white ? 'n' : 'N';
		if (board[i - 1][j + 2] == enemy)
		{
			return true;
		}
	}
	if (i - 2 >= 0 && j - 1 >= 0)
	{
		int enemy = white ? 'n' : 'N';
		if (board[i - 2][j - 1] == enemy)
		{
			return true;
		}
	}
	if (i - 2 >= 0 && j + 1 <= 7)
	{
		int enemy = white ? 'n' : 'N';
		if (board[i - 2][j + 1] == enemy)
		{
			return true;
		}
	}
	if (i + 1 <= 7 && j - 2 >= 0)
	{
		int enemy = white ? 'n' : 'N';
		if (board[i + 1][j - 2] == enemy)
		{
			return true;
		}
	}
	if (i + 1 <= 7 && j + 2 <= 7)
	{
		int enemy = white ? 'n' : 'N';
		if (board[i + 1][j + 2] == enemy)
		{
			return true;
		}
	}
	if (i + 2 <= 7 && j - 1 >= 0)
	{
		int enemy = white ? 'n' : 'N';
		if (board[i + 2][j - 1] == enemy)
		{
			return true;
		}
	}
	if (i + 2 <= 7 && j + 1 <= 7)
	{
		int enemy = white ? 'n' : 'N';
		if (board[i + 2][j + 1] == enemy)
		{
			return true;
		}
	}
	int si = i, sj = j;
	int rEnemy = white ? 'r' : 'R';
	int bEnemy = white ? 'b' : 'B';
	int qEnemy = white ? 'q' : 'Q';

	// Check for rook and queen
	for (si = i, sj = j - 1; sj >= 0; sj--)
	{
		if (board[si][sj] == qEnemy || board[si][sj] == rEnemy)
		{
			return true;
		}
		else if (board[si][sj] != '.')
		{
			break;
		}
	}
	for (si = i, sj = j + 1; sj <= 7; sj++)
	{
		if (board[si][sj] == qEnemy || board[si][sj] == rEnemy)
		{
			return true;
		}
		else if (board[si][sj] != '.')
		{
			break;
		}
	}
	for (si = i - 1, sj = j; si >= 0; si--)
	{
		if (board[si][sj] == qEnemy || board[si][sj] == rEnemy)
		{
			return true;
		}
		else if (board[si][sj] != '.')
		{
			break;
		}
	}
	for (si = i + 1, sj = j; si <= 7; si++)
	{
		if (board[si][sj] == qEnemy || board[si][sj] == rEnemy)
		{
			return true;
		}
		else if (board[si][sj] != '.')
		{
			break;
		}
	}

	// check for bishop and queen
	for (si = i - 1, sj = j - 1; si >= 0 && sj >= 0; si--, sj--)
	{
		if (board[si][sj] == qEnemy || board[si][sj] == bEnemy)
		{
			return true;
		}
		else if (board[si][sj] != '.')
		{
			break;
		}
	}
	for (si = i - 1, sj = j + 1; si >= 0 && sj <= 7; si--, sj++)
	{
		if (board[si][sj] == qEnemy || board[si][sj] == bEnemy)
		{
			return true;
		}
		else if (board[si][sj] != '.')
		{
			break;
		}
	}
	for (si = i + 1, sj = j - 1; si <= 7 && sj >= 0; si++, sj--)
	{
		if (board[si][sj] == qEnemy || board[si][sj] == bEnemy)
		{
			return true;
		}
		else if (board[si][sj] != '.')
		{
			break;
		}
	}
	for (si = i + 1, sj = j + 1; si <= 7 && sj <= 7; si++, sj++)
	{
		if (board[si][sj] == qEnemy || board[si][sj] == bEnemy)
		{
			return true;
		}
		else if (board[si][sj] != '.')
		{
			break;
		}
	}
	return false;
}

int main()
{
	int index = 1;
	string row;
	bool piecePresent, whiteDanger, blackDanger;
	while (true)
	{
		whiteDanger = false;
		blackDanger = false;
		piecePresent = false;
		for (int i = 0; i < 8; i++)
		{
			cin >> row;
			for (int j = 0; j < 8; j++)
			{
				board[i][j] = 0;
				board[i][j] = row[j];
				if (row[j] != '.')
				{
					piecePresent = true;
				}
			}
		}
		if (!piecePresent)
		{
			break;
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'k')
				{
					blackDanger = checkDanger(i, j, false);
				}
				if (board[i][j] == 'K')
				{
					whiteDanger = checkDanger(i, j, true);
				}
				if (whiteDanger || blackDanger)
				{
					break;
				}
			}
			if (whiteDanger || blackDanger)
			{
				break;
			}
		}
		cout << "Game #" << index++ << ": ";
		if (blackDanger)
		{
			cout << "black king is in check." << endl;
		}
		else if (whiteDanger)
		{
			cout << "white king is in check." << endl;
		}
		else
		{
			cout << "no king is in check." << endl;
		}
	}
	return 0;
}