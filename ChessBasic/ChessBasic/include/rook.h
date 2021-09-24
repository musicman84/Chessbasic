#pragma once
#include "piece.h"
class rook : public piece {
public:
	rook(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible = true);
	
	virtual void sayHi();
	
	string getPieceType();
};