#pragma once
#include "board.h"
class game //Runs game
{
private:
	char view, viewArr[100], pColour, pColourArr[100], numPcha, numPchaArr[100];
	player* turn[2];

	int turnCount = 0;
	bool checkMate = false;
	board cBoard;

public:
	game();
	~game(); 
};