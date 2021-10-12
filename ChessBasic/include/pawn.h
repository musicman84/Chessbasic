#pragma once

#include "piece.h"

class pawn : public piece {
public:
	pawn(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible = true);
	virtual void sayHi();
	string getPieceType();
	void allLegalMoves();
private:
	void lineOfSight(int vectorRow, int vectorCol, int maxDist = 9);
	void pawnTakingSight(int vectorRow, int vectorCol, int maxDist = 9);
};