#include "knight.h"
	knight::knight(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void knight::sayHi() {
		cout << "Knight " << "colour " << colour << " column " << column << " row " << row << endl;
	}
	string knight::getPieceType() {
		return "n";
	}
	void knight::allLegalMoves() {//default is false for each square
		//legalMoveArray, first index is column, second is row
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((j == (row + 2) || j == (row - 2)) && (i == (column + 1) || i == (column - 1))) {
					if (squareStatus(i, j) == 'e') {// square is empty
						legalMove[i][j] = 1;
					}
					else if (squareStatus(i, j) == 'o') {//square has oppoonent's piece on it (other than king)
						legalMove[i][j] = 2;
					}
					else if (squareStatus(i, j) == 'k') {//square has oppoonent's piece on it (other than king)
						legalMove[i][j] = 3;
					}
					else if (squareStatus(i, j) == 's') {//square has oppoonent's piece on it (other than king)
						legalMove[i][j] = 0;
					}
					else exit(594);
				}
				if ((i == (column + 2) || i == (column - 2)) && (j == (row + 1) || j == (row - 1))) {
					if (squareStatus(i, j) == 'e') {// square is empty
						legalMove[i][j] = 1;
					}
					else if (squareStatus(i, j) == 'o') {//square has oppoonent's piece on it (other than king)
						legalMove[i][j] = 2;
					}
					else if (squareStatus(i, j) == 'k') {//square has oppoonent's piece on it (other than king)
						legalMove[i][j] = 3;
					}
					else if (squareStatus(i, j) == 's') {//square has oppoonent's piece on it (other than king)
						legalMove[i][j] = 0;
					}
					else exit(594);
				}
			}
		}

	}