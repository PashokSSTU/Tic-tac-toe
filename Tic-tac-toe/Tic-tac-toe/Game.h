#pragma once
#include "Board.h"
#include "AI.h"

class Game
{
private:
	char humPlayer = 'X';
	char aiPlayer = 'O';
	
public:
	Board brd;
	Game()
	{}
	~Game()
	{}

};

