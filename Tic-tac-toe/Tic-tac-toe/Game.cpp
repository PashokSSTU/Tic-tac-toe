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
		aiPlayer = 'X';
		cout << endl << "You choosed \"O\"" << endl;
		break;
	default:
		cout << endl << "Error! Incorrect value" << endl;
		exit(1);
		break;
	}
	process = new GameProcessing(humPlayer, &board);
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
	if (process->isWinning(humPlayer))
	{
		cout << endl << "Player is winning!" << endl;
		return true;
	}
	else if(process->isWinning(aiPlayer))
	{
		cout << endl << "AI is winning!" << endl;
		return true;
	}
	else if ((board.getAmountFreeCeils() == 0))
	{
		cout << endl << "Tie!" << endl;
		return true;
	}

	return false;
}