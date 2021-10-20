#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	Game TicTacToe;
	TicTacToe.board.Display();

	while (!TicTacToe.isOver())
	{
		int choise;

		// ��� ������
		cout << "Your move: ";
		cin >> choise;
		TicTacToe.board.Choose(choise, TicTacToe.getHumPlayer());
		cout << endl;
		
		TicTacToe.board.Display();
		
		// ��� ��
		cout << endl << "AI move: ";
		TicTacToe.AIMove();

		TicTacToe.board.Display();
	}
	return 0;
}