#pragma once
#include "Board.h"
#include "GameProcessing.h"
#include <vector>

using namespace std;

class AI
{
private:
	struct Move 
	{
		int x;
		int y;
		int score;
	} bestMove;

	Board* brd;
	GameProcessing* process;

public:

	AI(Board* _brd, GameProcessing* _process);

	~AI()
	{}

	int minimax(int depth, bool isAI);
	void makeBestMove();
};

