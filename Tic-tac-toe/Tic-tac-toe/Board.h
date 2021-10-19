#pragma once
#include <iostream>

class Board
{
private:
	char board[3][3];
public:
	Board();
	~Board()
	{}

	void Display();
	void Choose(int num, char player);
};

