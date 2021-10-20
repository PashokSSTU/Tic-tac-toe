#include "AI.h"
#include <algorithm>
#include <vector>

using namespace std;

AI::AI(Board* _brd, GameProcessing* _process) :brd(_brd), process(_process)
{
	bestMove.x = -1;
	bestMove.y = -1;
}


int AI::minimax(int depth, bool isAI)
{
	if (process->AIWinning())
	{
		return 10;
	}

	if (process->HumanWinning())
	{
		return -10;
	}

	if (brd->getAmountFreeCeils() == 0)
	{
		return 0;
	}

	if (isAI)
	{
		int bestScore = -1000000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (brd->board_arr[i][j] != 'X' && brd->board_arr[i][j] != 'O')
				{
					brd->Choose(3 * i + j + 1, process->getAIPlayer());

					bestScore = max(bestScore, minimax(depth + 1, false));

					brd->Choose(3 * i + j + 1, (char)(3 * i + j + 1) + 48);
					brd->incrAmountFreeCeils();
				}
			}
		}
		return bestScore;
	}
	else
	{
		int bestScore = 1000000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (brd->board_arr[i][j] != 'X' && brd->board_arr[i][j] != 'O')
				{
					brd->Choose(3 * i + j + 1, process->getAIPlayer());

					bestScore = min(bestScore, minimax(depth + 1, true));

					brd->Choose(3 * i + j + 1, (char)(3 * i + j + 1) + 48);
					brd->incrAmountFreeCeils();
				}
			}
		}
		return bestScore;
	}
}

void AI::makeBestMove()
{
	vector<Move> nextMoves;

	// Установка лучшего хода для ИИ
	int bestScore = -1000000;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			brd->Choose(3 * i + j + 1, process->getAIPlayer());

			bestScore = min(bestScore, minimax(0, true));

			Move move;
			move.x = i;
			move.y = j;
			move.score = bestScore;

			nextMoves.push_back(move);

			brd->Choose(3 * i + j + 1, (char)(3 * i + j + 1) + 48);
			brd->incrAmountFreeCeils();

		}
	}

	bestScore = -1000000;
	int index = -1;

	for (int i = 0; i < nextMoves.size(); i++)
	{
		if (nextMoves[i].score > bestScore)
		{
			bestScore = nextMoves[i].score;
			index = i;
		}
	}

	bestMove = nextMoves[index];

	brd->Choose(3 * bestMove.x + bestMove.y + 1, process->getAIPlayer());
}