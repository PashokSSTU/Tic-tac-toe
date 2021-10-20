#pragma once
#include "Board.h"

class GameProcessing
{
private:
	char humPlayer;
	char aiPlayer;
	Board* brd;
public:
	GameProcessing(char hum, Board* _brd);

	~GameProcessing()
	{}

	bool isWinning(char player);
	bool HumanWinning() { return isWinning(humPlayer); }
	bool AIWinning() { return isWinning(aiPlayer); }
	char getHumPlayer() { return humPlayer; }
	char getAIPlayer() { return aiPlayer; }
};

