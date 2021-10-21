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
	bool player::initialCalcsShowCheckMate() {//work out all legal moves and check for Checkmate,
		(*ownPieces)->setAllLegalMoveArrays();//calulate all legal move arrays
		(*ownPieces)->applyCheckToOwnPieces();//apply Check rule (only to pieces of same colour)
		if ((*ownPieces)->isCheckMate()) {
			cout << "Check Mate\n";
			return (true);
		}
		if ((*ownPieces)->isInCheck()) {//check for Check
			cout << "Check\n";
		}
		return(false);
	}
	