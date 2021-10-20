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
		aiPlayer = 'O';
		cout << endl << "You choosed \"X\"" << endl;
		break;
	case 2:
		humPlayer = 'O';
		aiPlayer = 'O';
		cout << endl << "You choosed \"O\"" << endl;
		break;
	default:
		cout << endl << "Error! Incorrect value" << endl;
		exit(1);
		break;
	}
	process = new GameProcessing(ch, &board);
	ai = new AI(&board, process);
}

Game::~Game()
{
	delete process;
	delete ai;

	process = nullptr;
	ai = nullptr;
}

bool Game::isOver()
{
	if (process->isWinning(humPlayer) || process->isWinning(aiPlayer) || (board.getAmountFreeCeils() == 0))
		return true;
	
	return false;
}