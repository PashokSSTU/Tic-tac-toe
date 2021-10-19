#include "Board.h"

using namespace std;

Board::Board()
{
	int count = 48; // 0 в ASCII кодировке после конвертации в char

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board_arr[i][j] = (char)(++count);
		}
	}
}

void Board::Display()
{
	cout << endl;
	cout << "   |   |   " << endl;
	cout << " " << board_arr[0][0] << " | " << board_arr[0][1] << " | " << board_arr[0][2] << endl;
	cout << "   |   |   " << endl;
	cout << "-----------" << endl;
	cout << "   |   |   " << endl;
	cout << " " << board_arr[1][0] << " | " << board_arr[1][1] << " | " << board_arr[1][2] << endl;
	cout << "   |   |   " << endl;
	cout << "-----------" << endl;
	cout << "   |   |   " << endl;
	cout << " " << board_arr[2][0] << " | " << board_arr[2][1] << " | " << board_arr[2][2] << endl;
	cout << "   |   |   " << endl;
	cout << endl;
}

void Board::Choose(int num, char player)
{
	board_arr[num / 3][num % 3 - 1] = player;
}

