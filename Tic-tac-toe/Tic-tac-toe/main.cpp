#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	char ch = 'Y';

	while (ch == 'Y')
	{
		Game TicTacToe; 
		TicTacToe.Launch(); // Начало игры
		cout << "Would you like restart game? [Y/N]" << endl;
		cin >> ch;

		if (ch != 'Y' && ch != 'N')
		{
			cout << "Error! Incorrect value." << endl;
			cout << "Would you like restart game? [Y/N]: ";
			cin >> ch;
			cout << endl;
		}
	}

	return 0;
}