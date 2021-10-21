#include "AI.h"
#include <vector>

using namespace std;

AI::AI(Board* _brd, GameProcessing* _process) :brd(_brd), process(_process)
{
	bestMove.x = -1;
	bestMove.y = -1;
}


int AI::minimax(int depth, bool isAI)
{
	count++;
	if (process->AIWinning())
	{
		return /*depth -*/ 10;
	}

	if (process->HumanWinning())
	{
		return -10 /*- depth*/;
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
				if (brd->board_arr[i][j] != 'X' && brd->board_arr[i][j] != 'O') // Проверка на пустоту
				{
					brd->Choose(3 * i + j + 1, process->getAIPlayer()); // Делаем ход

					bestScore = max(bestScore, minimax(depth + 1, false));

					brd->Choose(3 * i + j + 1, ' '); // Убираем ход
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
				if (brd->board_arr[i][j] != 'X' && brd->board_arr[i][j] != 'O') // Проверка на пустоту
				{
					brd->Choose(3 * i + j + 1, process->getHumPlayer()); // Делаем ход

					bestScore = min(bestScore, minimax(depth + 1, true));

					brd->Choose(3 * i + j + 1, ' '); // Убираем ход
				}
			}
		}
		return bestScore;
	}
}

void AI::makeBestMove()
{
	if (brd->amountFreeCeils == 0)
	{
		return;
	}

	vector<Move> nextMoves(0);

	// Создание вектора возможных ходов
	int bestScore = -1000000;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (brd->board_arr[i][j] != 'X' && brd->board_arr[i][j] != 'O') // Проверка на пустоту
			{
				bestScore = max(bestScore, minimax(0, true));

				Move move;
				move.x = i;
				move.y = j;
				move.score = bestScore;

				nextMoves.push_back(move);
			}
		}
	}

	// Выборка наилучшего хода для ИИ
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

	bestMove.x = nextMoves[index].x;
	bestMove.y = nextMoves[index].y;
	bestMove.score = nextMoves[index].score;

	if ((bestMove.x == bestMove.y) && (bestMove.x == -1))
	{
		cout << "Error! Invavied move from AI!" << endl;
		exit(-1);
	}

	brd->Choose(3 * bestMove.x + bestMove.y + 1, process->getAIPlayer());
}