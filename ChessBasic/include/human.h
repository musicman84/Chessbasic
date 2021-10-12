#pragma once
#include "player.h"
class human :public player {//human user
private:
	piece* currentPiece;
public:
	human(piece** ownPiecesPar, int ownPieceCountPar, piece** oppPiecesPar, int oppPieceCountPar, string Name = "Default");
	void takeTurn(); 

	//bool checkDestLocation(int col, int row); 

	bool checkCoordOwnPiece(int col, int row);

	piece* findPieceFromCoord(int col, int row);

	int convertColCoord(string original);//converts A=0, B=1 etc
	
	int convertRowCoord(string original);//converts "0"=0, "1"=1 etc
};