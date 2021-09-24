#pragma once
#include "piece.h"

class bishop : public piece {
public:
	bishop(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible = true);
	
	virtual void sayHi();
	string getPieceType();
};