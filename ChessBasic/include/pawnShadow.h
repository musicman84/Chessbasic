#pragma once
#include "piece.h"
using namespace std;
class pawnShadow : public piece {//used for en passant?
public:
	pawnShadow(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible = true) ;
	virtual void sayHi();
	string getPieceType(); 
	void allLegalMoves();
};