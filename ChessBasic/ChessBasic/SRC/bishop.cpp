#include "piece.h"
#include "bishop.h"

	bishop::bishop(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void bishop::sayHi() {
		cout << "Bishop " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string bishop::getPieceType() {
		return "b";
	}