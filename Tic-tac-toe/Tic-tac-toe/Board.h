#pragma once
#include <iostream>

class Game;

class Board
{
private:
	char board_arr[3][3];
	int amountFreeCeils;
public:
	Board();
	~Board()
	{}

	void Display();
	bool Choose(int num, char player);
	int getAmountFreeCeils() { return amountFreeCeils; }
	void setAmountFreeCeils(int num) { amountFreeCeils = num; }

	friend class GameProcessing;
	friend class AI;
};

