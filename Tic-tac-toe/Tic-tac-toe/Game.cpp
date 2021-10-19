#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{
	int ch;
	cout << "Do you choose \"X\" or \"O\"? [1/2]: ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		humPlayer = 'X';
		cout << "You choosed \"X\"" << endl;
		break;
	case 2:
		humPlayer = 'O';
		cout << "You choosed \"O\"" << endl;
		break;
	default:
		cout << "Error! Incorrect value" << endl;
		exit(1);
		break;
	}
}

bool Game::isOver()
{
	for (int i = 0; i < 3; i++)
	{
		if ((board.board_arr[i][0] == board.board_arr[i][1] && board.board_arr[i][0] == board.board_arr[i][2]) ||
			(board.board_arr[0][i] == board.board_arr[1][i] && board.board_arr[0][i] == board.board_arr[2][i]))
		{
			return true;
		}
	}
	if ((board.board_arr[0][0] == board.board_arr[1][1] && board.board_arr[2][2] == board.board_arr[0][0]) ||
		(board.board_arr[0][2] == board.board_arr[1][1] && board.board_arr[2][0] == board.board_arr[0][2]))
	{
		return true;
	}
	return false;
}