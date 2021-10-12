#include "queen.h"
	queen::queen(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void queen::sayHi() {
		cout << "Queen " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string queen::getPieceType() {
		return "q";
	}
	void queen::allLegalMoves() {//default is false for each square
		//legalMoveArray, first index is column, second is row
		lineOfSight(1, 1);
		lineOfSight(-1, 1);
		lineOfSight(1, -1);
		lineOfSight(-1, -1);
		lineOfSight(0, 1);
		lineOfSight(0, -1);
		lineOfSight(1, 0);
		lineOfSight(-1, 0);
	}