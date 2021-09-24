#pragma once
#include "piece.h"
class knight : public piece {
public:
	knight(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible = true);
	virtual void sayHi();

	string getPieceType();
};