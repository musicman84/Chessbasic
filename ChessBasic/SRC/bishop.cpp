#include "piece.h"
#include "bishop.h"

	bishop::bishop(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void bishop::sayHi() {
		cout << "Bishop " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string bishop::getPieceType() {
		return "b";
	}
	void bishop::allLegalMoves() {//default is false for each square
		//legalMoveArray, first index is column, second is row
		lineOfSight(1, 1);
		lineOfSight(-1, 1);
		lineOfSight(1, -1);
		lineOfSight(-1, -1);
	}