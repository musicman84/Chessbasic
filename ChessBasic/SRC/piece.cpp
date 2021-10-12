#include "piece.h"
using namespace std;
piece::piece(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible, bool pieceYetToMove)
{
	colour = pieceColour;
	column = pieceColumn;
	row = pieceRow;
	visible = pieceVisible;//is piece visiable on the board?
	taken = false;
	yetToMove = pieceYetToMove;
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
void piece::movePieceTo(int colPar, int rowPar) {//moves piece and takes opposition piece
	//take piece if required
	if (squareStatus(colPar,rowPar) == 'o') {
		for (int i = 0; i < numOppositeColourPiece; i++) {
			if (oppositeColourPiecesPtr[i]->getColumn() == colPar && oppositeColourPiecesPtr[i]->getRow() == rowPar) {
				oppositeColourPiecesPtr[i]->setPieceIsTaken();
			}
		}
	}
	//move piece
	if (!taken) {
		column = colPar;
		row = rowPar;
		yetToMove = false;
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
void piece::setSameColourPieces(piece** samePieces) {
	sameColourPiecesPtr = samePieces;
};
void piece::setNumSameColourPiece(int num) {
	numSameColourPiece = num;
};
void piece::setOppositeColourPieces(piece** oppPieces) {
	oppositeColourPiecesPtr = oppPieces;
};
void piece::setNumOppositeColourPiece(int num) {
	numOppositeColourPiece = num;
};
void piece::test() {//can delete, used only for testing/debugging
	cout << "Same colour:\n";
	for (int i = 0; i < numSameColourPiece; i++) {
		sameColourPiecesPtr[i]->sayHi();
	}
	cout << "Opposite colour:\n";
	for (int i = 0; i < numOppositeColourPiece; i++) {
		oppositeColourPiecesPtr[i]->sayHi();
	}
}
bool piece::isMoveLegal(int colPar, int rowPar) {
	return legalMove[colPar][rowPar];
}
char piece::squareStatus(int col, int row) {//function returns char depending upon what is in the square 
	//'s' piece of same colour, o if opponent's piece (not king), k if opponent's king, e if empty
	for (int i = 0; i < numSameColourPiece; i++) {
		if (sameColourPiecesPtr[i]->getColumn() == col && sameColourPiecesPtr[i]->getRow() == row) {
			return 's';
		}
	}
	for (int i = 0; i < numOppositeColourPiece; i++) {
		if (oppositeColourPiecesPtr[i]->getColumn() == col && oppositeColourPiecesPtr[i]->getRow() == row) {
			if (oppositeColourPiecesPtr[i]->getPieceType() == "k") {
				return 'k';
			}
			else {
				return 'o';
			}
		}
	}
	return 'e';
}
void piece::lineOfSight(int vectorCol, int vectorRow, int maxDist){//note pawn has own version
	//cout << pawnException << endl;
	int newRow, newCol, iter = 1;
	newRow = row + (vectorRow*iter);
	newCol = column + (vectorCol*iter);
	//cout << "newRow " << newRow << " newCol " << newCol << endl;
	while (newRow < 8 && newRow >= 0 && newCol < 8 && newCol >= 0) {
		if (squareStatus(newCol, newRow) == 'e') {// square is empty
			legalMove[newCol][newRow] = 1;
		}
		else if (squareStatus(newCol, newRow) == 'o') {//square has oppoonent's piece on it (other than king)
			legalMove[newCol][newRow] = 2;		
			return;
		}
		else if (squareStatus(newCol, newRow) == 'k') {//square has oppoonent's king on it
			legalMove[newCol][newRow] = 3;
			return;
		}
		else if (squareStatus(newCol, newRow) == 's')//square has own piece on it
			return;

		if (iter >= maxDist) {
			return;
		}
		iter++;
		newRow = row + (vectorRow*iter);
		newCol = column + (vectorCol*iter);
	}

}
void piece::outputAllPossMoves() {
	bool first = true;
	cout << "legal moves are: ";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (legalMove[i][j]) {
				if (first) cout << numToLet(i) << j + 1;
				else cout << "," << numToLet(i)<< j+1;
				first = false;
			}
		}
	}
	cout << endl;
}
void piece::clearLegalMoveArray() {
	for (int i = 0; i < 8; i++) {
		for (int j=0; j < 8; j++) {
			legalMove[i][j]=0;
		}
	}
}
