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
		//TicTacToe.board.Choose(5, TicTacToe.getHumPlayer());
		//TicTacToe.board.Choose(7, TicTacToe.getHumPlayer());
		//TicTacToe.board.Choose(2, TicTacToe.getAIPlayer());
		//TicTacToe.board.Choose(3, TicTacToe.getAIPlayer());
		//TicTacToe.board.Choose(6, TicTacToe.getAIPlayer());

		//TicTacToe.board.Display();

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