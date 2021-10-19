#include <iostream>
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
	Game TicTacToe;
	TicTacToe.board.Display();
	while (!TicTacToe.isOver())
	{
		int ch;
		cout << "Your move: ";
		cin >> ch;
		TicTacToe.board.Choose(ch, TicTacToe.getHumPlayer());
		TicTacToe.board.Display();
	}
	return 0;
}