#include "king.h"

	king::king(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void king::sayHi() {
		cout << "King " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string king::getPieceType() {
		return "k";
	}
	void king::allLegalMoves() {//default is false for each square
		//legalMoveArray, first index is column, second is row
		lineOfSight(1, 1,1);
		lineOfSight(-1, 1, 1);
		lineOfSight(1, -1, 1);
		lineOfSight(-1, -1, 1);
		lineOfSight(0, 1, 1);
		lineOfSight(0, -1, 1);
		lineOfSight(1, 0, 1);
		lineOfSight(-1, 0, 1);

	}
