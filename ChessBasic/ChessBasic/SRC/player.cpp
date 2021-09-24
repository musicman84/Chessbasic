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
	void player::takePiece(piece* piecePar, int i) {
		piecePar->setPieceIsTaken();//clear dynamic array of piece

	}