#pragma once
#include "piece.h"
using namespace std;
class player {//parent class, for AI or Human
protected:
	string name, coordStart, coordFinish;
	int ownPieceCount, oppPieceCount, colStart, rowStart, colFinish, rowFinish;
	piece** ownPieces;
	piece** oppPieces;
	piece* pieceToMove;
public:
	//string name;
	player(piece** ownPiecesPar, int ownPieceCountPar, piece** oppPiecesPar, int oppPieceCountPar, string Name = "Default");
	
	virtual void takeTurn() = 0;
	void setName(string Name = "Default"); 
	bool initialCalcsShowCheckMate();
	virtual string getPlayerType() = 0;
};