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
	int count = 0;
public:
	AI(Board* _brd, GameProcessing* _process);

	~AI()
	{}

	//Вычисление оптимального хода
	int minimax(int depth, bool isAI, int alpha, int beta, vector<AI::Move>* moves = nullptr); 

	void makeBestMove(); // Функция вызова оптимального для ИИ хода
};

