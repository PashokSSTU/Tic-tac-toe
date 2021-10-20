#include "GameProcessing.h"

GameProcessing::GameProcessing(char hum, Board* _brd) :humPlayer(hum), brd(_brd)
{
	if (humPlayer == 'X')
		aiPlayer = 'O';
	else if(humPlayer == 'O')
		aiPlayer = 'X';
}

bool GameProcessing::isWinning(char player)
{
	for (int i = 0; i < 3; i++)
	{
		if ((brd->board_arr[i][0] == brd->board_arr[i][1] && brd->board_arr[i][0] == brd->board_arr[i][2] &&
			brd->board_arr[i][0] == player) ||
			(brd->board_arr[0][i] == brd->board_arr[1][i] && brd->board_arr[0][i] == brd->board_arr[2][i] &&
				brd->board_arr[0][i] == player))
		{
			return true;
		}
	}
	if ((brd->board_arr[0][0] == brd->board_arr[1][1] && brd->board_arr[2][2] == brd->board_arr[0][0] &&
		brd->board_arr[0][0] == player) ||
		(brd->board_arr[0][2] == brd->board_arr[1][1] && brd->board_arr[2][0] == brd->board_arr[0][2] &&
			brd->board_arr[0][2] == player))
	{
		return true;
	}
	return false;
}