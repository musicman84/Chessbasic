#pragma once

#include "piece.h"

class pawn : public piece {
public:
	pawn(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible = true);
	virtual void sayHi();
	string getPieceType();
};