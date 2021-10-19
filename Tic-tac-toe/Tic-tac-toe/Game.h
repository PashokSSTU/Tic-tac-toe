#pragma once
#include "Board.h"
#include "AI.h"

class Game
{
private:
	char humPlayer;
	char aiPlayer;
public:
	Board board;
	Game();
	~Game()
	{}

	bool isOver();
	char getHumPlayer() { return humPlayer; }
	char getAIPlayer() { return aiPlayer; }
};

