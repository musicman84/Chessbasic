#include "king.h"

	king::king(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void king::sayHi() {
		cout << "King " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string king::getPieceType() {
		return "k";
	}
