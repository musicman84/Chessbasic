#include "knight.h"
	knight::knight(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void knight::sayHi() {
		cout << "Knight " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string knight::getPieceType() {
		return "n";
	}