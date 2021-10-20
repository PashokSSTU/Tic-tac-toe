#include "AI.h"
#include <algorithm>

using namespace std;

AI::AI(Board* _brd, GameProcessing* _process) :brd(_brd), process(_process)
{
	bestMove.x = -1;
	bestMove.y = -1;
	bestMove.score = -1000;
}

int AI::minimax(int depth, bool isMaximize)
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

	if (isMaximize)
	{
		int bestScore = -1000000;
		int val;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (brd->board_arr[i][j] != 'X' && brd->board_arr[i][j] != 'O')
				{
					brd->Choose(3*i + j + 1, process->getHumPlayer());
					val = minimax(depth + 1, false);
					bestScore = max(bestScore, val);

					brd->board_arr[i][j] = (char)(3 * i + j + 1) + 48;
					brd->incrAmountFreeCeils();
					
					// Запись информации о ходе записываем лишь при первом вызове функции
					if (depth == 0)
					{
						bestMove.x = i;
						bestMove.y = j;
						bestMove.score = bestScore;

						availSpots.push_back(bestMove);
					}
				}
			}
		}

	}
	else
	{
		int bestScore = 1000000;
		int val;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (brd->board_arr[i][j] != 'X' && brd->board_arr[i][j] != 'O')
				{
					brd->Choose(3 * i + j + 1, process->getHumPlayer());
					val = minimax(depth + 1, true);
					bestScore = min(bestScore, val);

					brd->board_arr[i][j] = (char)(3 * i + j + 1) + 48;
					brd->incrAmountFreeCeils();

					// Запись информации о ходе записываем лишь при первом вызове функции
					if (depth == 0)
					{
						bestMove.x = i;
						bestMove.y = j;
						bestMove.score = bestScore;

						availSpots.push_back(bestMove);
					}
				}
			}
		}
	}
}

void AI::findBestMove(char player)
{
	if (player == process->getAIPlayer())
	{
		int bestScore = -1000000;

		for (int i = 0; i < availSpots.size(); i++)
		{
			if (availSpots[i].score > bestScore)
			{
				bestScore = availSpots[i].score;

				bestMove.x = availSpots[i].x;
				bestMove.y = availSpots[i].y;
				bestMove.score = availSpots[i].score;
			}
		}
	}
	else if(player == process->getHumPlayer())
	{
		int bestScore = 1000000;

		for (int i = 0; i < availSpots.size(); i++)
		{
			if (availSpots[i].score < bestScore)
			{
				bestScore = availSpots[i].score;

				bestMove.x = availSpots[i].x;
				bestMove.y = availSpots[i].y;
				bestMove.score = availSpots[i].score;
			}
		}
	}

}

void AI::makeBestMove()
{
	minimax(0, true);
	findBestMove(process->getAIPlayer());
	brd->Choose(3 * bestMove.x + bestMove.y + 1, process->getAIPlayer());
}