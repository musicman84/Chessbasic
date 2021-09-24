#include "pawnShadow.h"
using namespace std;
	pawnShadow::pawnShadow(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void pawnShadow::sayHi() {
		cout << "Pawnshadow " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string pawnShadow::getPieceType() {
		return "s";
	}
