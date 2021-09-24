#pragma once
#include <fstream>
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "human.h"
#include "AI.h"

using namespace std;
class board {//container class for pieces
private:
	//initialise counters
	int pieceNumber = 0;
	int whitePieceNum = 0;
	int blackPieceNum = 0;

	string boardStr[8][8];//first index is column (A-G), second is row (0-7)
	piece* allPieces[32];//array of pointers to each piece
	piece* whitePieces[16];//array of pointers to each white piece
	piece* blackPieces[16];//array of pointers to each black piece
public:
	board();
	~board();

	void setBoard();
	void loadBoard();
	void printBoard(char colour);
	int getPieceCount();

	int getWhitePieceCount();

	int getBlackPieceCount();

	piece** getWhitePieces();

	piece** getBlackPieces();

	char numToLet(int original);//convert ints to numbers for output only

};