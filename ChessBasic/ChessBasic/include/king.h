#pragma once
#include "piece.h"

class king : public piece {
public:
	king(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible = true);
	
	virtual void sayHi();

	string getPieceType();
};