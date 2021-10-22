#pragma once
#include "Board.h"

class GameProcessing
{
private:
	char humPlayer; // Обозначение игрока
	char aiPlayer; // Обозначение ИИ
	Board* brd;
public:
	GameProcessing(char hum, Board* _brd);

	~GameProcessing()
	{}

	bool isWinning(char player); // Проверка победы игрока/ИИ
	bool HumanWinning() { return isWinning(humPlayer); } // Проверка победы игрока
	bool AIWinning() { return isWinning(aiPlayer); } // Проверка победы ИИ
	char getHumPlayer() { return humPlayer; }
	char getAIPlayer() { return aiPlayer; }
};

