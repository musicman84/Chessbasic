#include "rook.h"
	rook::rook(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void rook::sayHi() {
		cout << "Rook " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string rook::getPieceType() {
		return "r";
	}