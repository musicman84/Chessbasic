#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class piece {//parent class, for all piece classes

protected:
	string colour;
	bool visible,taken;
	int column;
	int row;

public:
	piece(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible = true);

	virtual string getPieceType() = 0;//pure virtual method
	virtual void sayHi();
	int getColumn();
	int getRow();
	void movePieceTo(int colPar, int rowPar);
	bool getVisibility();
	bool getIsPieceTaken();
	void setPieceIsTaken();
};