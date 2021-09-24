#include "pawn.h"
using namespace std;
	pawn::pawn(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void pawn::sayHi() {
		cout << "Pawn " << "colour " << colour << " column " << column << " row " << row << " visible " << visible << endl;
	}
	string pawn::getPieceType() {
		return "p";
	}