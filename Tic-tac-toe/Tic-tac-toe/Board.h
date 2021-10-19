#pragma once
#include <iostream>

class Game;

class Board
{
private:
	char board_arr[3][3];
public:
	Board();
	~Board()
	{}

	void Display();
	void Choose(int num, char player);

	friend class Game;
};

