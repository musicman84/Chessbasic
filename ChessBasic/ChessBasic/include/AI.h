#pragma once
#include "player.h"
class AI :public player {
public:
	AI(piece** ownPiecesPar, int ownPieceCountPar, piece** oppPiecesPar, int oppPieceCountPar, string Name = "Default");
	void takeTurn();
};//Not to be implemented yet