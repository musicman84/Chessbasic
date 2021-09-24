#include "AI.h"
	AI::AI(piece** ownPiecesPar, int ownPieceCountPar, piece** oppPiecesPar, int oppPieceCountPar, string Name)
		:player(ownPiecesPar, ownPieceCountPar, oppPiecesPar, oppPieceCountPar, Name) {};
	void AI::takeTurn() {};
//Not to be implemented yet