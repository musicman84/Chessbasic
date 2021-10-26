#pragma once
#include "AImove.h"
class AI :public player {
private:
	vector <AImove> AllPossMovesForAI;
	int numberOfPosMoves;
public:
	AI(piece** ownPiecesPar, int ownPieceCountPar, piece** oppPiecesPar, int oppPieceCountPar, string Name = "Default");
	void takeTurn();
	string getPlayerType();
};//Not to be implemented yet