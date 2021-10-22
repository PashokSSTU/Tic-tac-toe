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
	bool Choose(int num, char player); // Функция осуществления хода
	int getAmountFreeCeils() { return amountFreeCeils; } // Получение количества свободных клеток

	friend class GameProcessing;
	friend class AI;
};

