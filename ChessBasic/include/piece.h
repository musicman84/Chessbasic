#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "genFunc.h"

using namespace std;
class piece {//parent class, for all piece classes

protected:
	string colour;
	bool visible,taken;
	int column;
	int row;
	piece** sameColourPiecesPtr;//pointer top first element within array
	int numSameColourPiece=0;
	piece** oppositeColourPiecesPtr;
	int numOppositeColourPiece=0;
	bool yetToMove;
	int legalMove[8][8] = { 0 };

public:
	piece(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible = true, bool pieceYetToMove =true);

	virtual string getPieceType() = 0;//pure virtual method
	virtual void sayHi();
	int getColumn();
	int getRow();
	void movePieceTo(int colPar, int rowPar);
	bool getVisibility();
	bool getIsPieceTaken();
	void setPieceIsTaken();
	void setSameColourPieces(piece** samePieces);
	void setNumSameColourPiece(int num);
	void setOppositeColourPieces(piece** samePieces);
	void setNumOppositeColourPiece(int num);
	void test();
	virtual bool isMoveLegal(int colPar, int rowPar);
	virtual void allLegalMoves()=0;
	char squareStatus(int col, int row);
	virtual void lineOfSight(int vectorRow, int vectorCol,int maxDist=9);
	void outputAllPossMoves();
	void clearLegalMoveArray();
};