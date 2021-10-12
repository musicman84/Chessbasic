#pragma once
#include "piece.h"

class queen : public piece {
public:
	queen(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible = true);
	
	virtual void sayHi();
	string getPieceType();
	void allLegalMoves();
};