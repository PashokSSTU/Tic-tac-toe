#pragma once
#include "GameProcessing.h"
#include "Board.h"
#include "AI.h"

class Game
{
private:
	char humPlayer;
	char aiPlayer;

	GameProcessing* process;
	AI* ai;	
public:
	Board board;
	Game();
	~Game();

	bool isOver();
	char getHumPlayer() { return humPlayer; }
	char getAIPlayer() { return aiPlayer; }
	void AIMove() { ai->makeBestMove(); }
};

