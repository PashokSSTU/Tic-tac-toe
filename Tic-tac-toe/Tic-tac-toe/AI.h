#pragma once
#include "Board.h"
#include "GameProcessing.h"
#include <vector>

using namespace std;

class AI
{
private:
	struct BestMove 
	{
		int x;
		int y;
		int score;
	} bestMove;

	vector<BestMove> availSpots; // Вектор с возможными ходами и их оценками для ИИ

	Board* brd;
	GameProcessing* process;

	int minimax(int depth, bool isMaximize);
public:
	AI(Board* _brd, GameProcessing* _process);

	~AI()
	{}

	void findBestMove(char player);
	void makeBestMove();
};

