#include "pawnShadow.h"
using namespace std;
	pawnShadow::pawnShadow(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void pawnShadow::sayHi() {
		cout << "Pawnshadow " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string pawnShadow::getPieceType() {
		return "s";
	}
	void pawnShadow::allLegalMoves() {//default is false for each square
		//legalMoveArray, first index is column, second is row
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				legalMove[i][j] = false;
			}
		}

	}
