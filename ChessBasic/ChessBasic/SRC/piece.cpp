#include "piece.h"
using namespace std;
piece::piece(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible)
{
	colour = pieceColour;
	column = pieceColumn;
	row = pieceRow;
	visible = pieceVisible;//is piece visiable on the board?
	taken = false;
}
//	string piece::getPieceType() {};//pure virtual method
void piece::sayHi() {
	cout << "General Piece " << "colour " << colour << " column " << column << " row " << row << endl;
}
int piece::getColumn() {
	if (!taken) {
		return column;
	}
	else {
		return 101;
	}
}
int piece::getRow() {
	if (!taken) {
		return row;
	}
	else {
		return 101;
	}
}
void piece::movePieceTo(int colPar, int rowPar) {
	if (!taken) {
		column = colPar;
		row = rowPar;
	}
}
bool piece::getVisibility() {
	if (!taken) {
		return visible;
	}
	else {
		return false;
	}
}
bool piece::getIsPieceTaken() {
	return taken;
}
void piece::setPieceIsTaken(){
	taken = true;
};