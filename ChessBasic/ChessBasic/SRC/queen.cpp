#include "queen.h"
	queen::queen(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void queen::sayHi() {
		cout << "Queen " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string queen::getPieceType() {
		return "q";
	}