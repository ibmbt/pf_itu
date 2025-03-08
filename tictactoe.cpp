#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;
char BOARD[ROWS][COLS];

void initialize_board();
void display_board();
bool valid_move(int r, int c);
void move(int r, int c, char symbol);
bool check_rows(char symbol);
bool check_cols(char symbol);
bool check_main_diagonal(char symbol);
bool check_second_diagonal(char symbol);
bool win_check(char symbol);
bool draw();
void turn_change(int &turn);
bool winning_move_made(char symbol);
bool blocked_opponent(char symbol);
void random_move(char symbol);
void ai_move(char symbol);
void replay(char &choice);

int main()
{
	char repeat = 'Y';
	int r = 0, c = 0;
	char choice;
	while (repeat == 'Y' || repeat == 'y')
	{
		cout << "\n===|TIC TAC TOE|===\n"
			 << endl;
		cout << "\n[1] VS AI" << endl;
		cout << "[2] VS PLAYER 2\n"
			 << endl;
		cin >> choice;
		if (choice == '1')
		{
			int turn = 0;
			char symbol = 'O';
			cout << "===|TIC TAC TOE|===\n"
				 << endl;
			initialize_board();
			display_board();
			while (true)
			{

				if (turn == 0)
				{
					symbol = 'O';
					do
					{
						cin >> r >> c;
						if (!(valid_move(r, c)))
						{
							cout << "INVALID MOVE, SELECT ANOTHER CELL." << endl;
						}
					} while (!(valid_move(r, c)));
					move(r, c, symbol);
					cout << "\nPLAYER 1 TOOK THE TURN.\n\n";
				}
				else if (turn == 1)
				{
					symbol = 'X';
					ai_move(symbol);
					cout << "AI TOOK THE TURN.\n\n";
				}

				display_board();

				if (win_check(symbol))
				{
					if (turn == 0)
						cout << "\nPLAYER 1 WINS!\n"
							 << endl;
					if (turn == 1)
						cout << "\nAI WINS!\n"
							 << endl;
					break;
				}
				if (draw())
				{
					cout << "\nGAME ENDED IN A DRAW!\n"
						 << endl;
					break;
				}
				turn_change(turn);

				cout << endl;
				cout << endl;
			}
		}
		else if (choice == '2')
		{
			int turn = 0;
			char symbol = 'O';
			cout << "===|TIC TAC TOE|===\n"
				 << endl;
			initialize_board();
			display_board();

			while (true)
			{

				if (turn == 0)
				{
					symbol = 'O';
					do
					{
						cin >> r >> c;
						if (!(valid_move(r, c)))
						{
							cout << "INVALID MOVE, SELECT ANOTHER CELL." << endl;
						}
					} while (!(valid_move(r, c)));
					move(r, c, symbol);
					cout << "\nPLAYER 1 TOOK THE TURN.\n\n";
				}
				else if (turn == 1)
				{
					symbol = 'X';
					do
					{
						cin >> r >> c;
						if (!(valid_move(r, c)))
						{
							cout << "INVALID MOVE, SELECT ANOTHER CELL." << endl;
						}
					} while (!(valid_move(r, c)));
					move(r, c, symbol);
					cout << "\nPLAYER 2 TOOK THE TURN.\n\n";
				}

				display_board();

				if (win_check(symbol))
				{
					if (turn == 0)
						cout << "\nPLAYER 1 WINS!\n"
							 << endl;
					if (turn == 1)
						cout << "\nPLAYER 2 WINS!\n"
							 << endl;
					break;
				}
				if (draw())
				{
					cout << "\nGAME ENDED IN A DRAW!\n"
						 << endl;
					break;
				}
				turn_change(turn);

				cout << endl;
				cout << endl;
			}
		}
		else
		{
			cout << "INVALID ENTRY" << endl;
		}

		replay(repeat);
		if ((repeat != 'y') && (repeat != 'Y'))
			cout << "THANK YOU FOR PLAYING.." << endl;
	}
	return 0;
}

void initialize_board()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			BOARD[i][j] = ' ';
		}
	}
}

void display_board()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (j == 0)
			{
				cout << "  ";
			}
			cout << BOARD[i][j];
			if (j < 2)
			{
				cout << "  |  ";
			}
		}
		cout << endl;
		if (i < 2)
			cout << "-----------------" << endl;
	}
}

bool valid_move(int r, int c)
{

	return (r >= 0 && r < 3 && c >= 0 && c < 3 && BOARD[r][c] == ' ');
}

void move(int r, int c, char symbol)
{
	BOARD[r][c] = symbol;
}

bool check_rows(char symbol) {

	for (int i = 0; i < ROWS; i++)
	{
		if ((BOARD[i][0] == symbol) &&
			(BOARD[i][1] == symbol) &&
			(BOARD[i][2] == symbol))
		{
			return true;
		}
	}
	return false;
}

bool check_cols(char symbol) {

	for (int i = 0; i < ROWS; i++)
	{
		if ((BOARD[0][i] == symbol) &&
			(BOARD[1][i] == symbol) &&
			(BOARD[2][i] == symbol))
		{
			return true;
		}
	}
	return false;
}

bool check_main_diagonal(char symbol) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if ((i == j) && (BOARD[i][j] != symbol)) {
				return false;
			}
		}
	}
	return true;
}

bool check_second_diagonal(char symbol) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if ((i+j == COLS-1) && (BOARD[i][j] != symbol)) {
				return false;
			}
		}
	}
	return true;
}

bool win_check(char symbol)
{
	/*
	for (int i = 0; i < ROWS; i++)
	{
		if ((BOARD[i][0] == symbol) &&
			(BOARD[i][1] == symbol) &&
			(BOARD[i][2] == symbol))
		{
			return true;
		}
		if ((BOARD[0][i] == symbol) &&
			(BOARD[1][i] == symbol) &&
			(BOARD[2][i] == symbol))
		{
			return true;
		}
	}

	if ((BOARD[0][0] == symbol) &&
		(BOARD[1][1] == symbol) &&
		(BOARD[2][2] == symbol))
	{
		return true;
	}

	if ((BOARD[0][2] == symbol) &&
		(BOARD[1][1] == symbol) &&
		(BOARD[2][0] == symbol))
	{
		return true;
	}
	*/


	if ((check_rows(symbol)) ||
		(check_cols(symbol)) ||
		(check_main_diagonal(symbol)) ||
		(check_second_diagonal(symbol))) {
		return true;
	}

	return false;
}

bool draw()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (BOARD[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

void turn_change(int &turn)
{
	turn++;
	turn = turn % 2;
}

bool winning_move_made(char symbol)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (BOARD[i][j] == ' ')
			{
				BOARD[i][j] = symbol;
				if (win_check(symbol))
				{
					return true;
				}
				BOARD[i][j] = ' ';
			}
		}
	}
	return false;
}

bool blocked_opponent(char symbol)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (BOARD[i][j] == ' ')
			{
				BOARD[i][j] = 'O';
				if (win_check('O'))
				{
					BOARD[i][j] = symbol;
					return true;
				}
				BOARD[i][j] = ' ';
			}
		}
	}
	return false;
}

void random_move(char symbol)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (BOARD[i][j] == ' ')
			{
				BOARD[i][j] = symbol;
				return;
			}
		}
	}
}

void ai_move(char symbol)
{

	if (winning_move_made(symbol))
	{
		return;
	}
	else if (blocked_opponent(symbol))
	{
		return;
	}
	else
	{
		random_move(symbol);
	}
}

void replay(char &choice)
{
	cout << "DO YOU WANT TO PLAY AGAIN? (Y/N):" << endl;
	cin >> choice;
}