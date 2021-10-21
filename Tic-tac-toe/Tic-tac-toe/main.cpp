#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	Game TicTacToe;
	TicTacToe.board.Display();

	while (1)
	{
		int choise;

		// Ход игрока
		cout << "Your move: ";
		cin >> choise;
		while (!TicTacToe.board.Choose(choise, TicTacToe.getHumPlayer()))
		{
			cout << "Your move: ";
			cin >> choise;
		}
		cout << endl;
		
		TicTacToe.board.Display();

		if (TicTacToe.isOver())
		{
			break;
		}
		
		// Ход ИИ
		cout << endl << "AI move: ";
		TicTacToe.AIMove();
		TicTacToe.board.Display();

		if (TicTacToe.isOver())
		{
			break;
		}
	}
	return 0;
}