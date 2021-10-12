#include "rook.h"
	rook::rook(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void rook::sayHi() {
		cout << "Rook " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string rook::getPieceType() {
		return "r";
	}
	void rook::allLegalMoves() {//default is false for each square
		//legalMoveArray, first index is column, second is row
		lineOfSight(0, 1);
		lineOfSight(0, -1);
		lineOfSight(1, 0);
		lineOfSight(-1, 0);

	}