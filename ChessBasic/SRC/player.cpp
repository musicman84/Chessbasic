#include "player.h"
using namespace std;
	player::player(piece** ownPiecesPar, int ownPieceCountPar, piece** oppPiecesPar, int oppPieceCountPar, string Name) {
		name = Name;

		ownPieces = ownPiecesPar;
		oppPieces = oppPiecesPar;
		ownPieceCount = ownPieceCountPar;
		oppPieceCount = oppPieceCountPar;
		//testing
		//cout << ownPieces << endl;

	}
	void player::takeTurn() {};
	void player::setName(string Name) {
		name = Name;
	}
	void player::clearLegalMoveArray(){
		for (int i = 0; i < ownPieceCount; i++) {
			ownPieces[i]->clearLegalMoveArray();
		}
		for (int i = 0; i < oppPieceCount; i++) {
			oppPieces[i]->clearLegalMoveArray();
		}
	}
	void player::setLegalMoveArray() {
		for (int i = 0; i < ownPieceCount; i++) {
			ownPieces[i]->allLegalMoves();;
		}
		for (int i = 0; i < oppPieceCount; i++) {
			oppPieces[i]->allLegalMoves();;
		}
	}