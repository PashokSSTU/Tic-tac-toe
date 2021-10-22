#pragma once
#include "GameProcessing.h"
#include "Board.h"
#include "AI.h"

class Game
{
private:
	char humPlayer; // Обозначение игрока
	char aiPlayer; // Обозначение ИИ

	GameProcessing* process;
	AI* ai;	
public:
	Board board;
	Game();
	~Game();

	void Launch(); // Запуск игры
	bool isOver(); // Проверка игры на завершение
	char getHumPlayer() { return humPlayer; } 
	char getAIPlayer() { return aiPlayer; }
	void AIMove() { ai->makeBestMove(); } // Функция вызова хода ИИ
};

