#include "pawn.h"
using namespace std;
	pawn::pawn(string pieceColour, int pieceColumn, int pieceRow, bool pieceVisible) :piece(pieceColour, pieceColumn, pieceRow, pieceVisible) {}
	void pawn::sayHi() {
		cout << "Pawn " << "colour " << colour << " column " << column << " row " << row << " visible " << visible << endl;
	}
	string pawn::getPieceType() {
		return "p";
	}

	void pawn::allLegalMoves() {//default is false for each square
		int moveDist = 1;		
		if (colour == "W") {
			if (yetToMove == true && row == 1) {// double checking that pawn is allowed to move two places
				moveDist = 2;
			}
			lineOfSight(0, 1, moveDist);
			pawnTakingSight(1, 1, 1);
			pawnTakingSight(-1, 1, 1);
		}
		else if (colour == "B") {
			if (yetToMove == true && row == 6) {// double checking that pawn is allowed to move two places
				moveDist = 2;
			}
			lineOfSight(0, -1, moveDist);
			pawnTakingSight(1, -1, 1);
			pawnTakingSight(-1, -1, 1);
		}
		else
		{
			exit(232);
		}
	}
	void pawn::lineOfSight(int vectorCol, int vectorRow, int maxDist) {
		int newRow, newCol, iter = 1;
		newRow = row + (vectorRow*iter);
		newCol = column + (vectorCol*iter);
		//cout << "oldrow "<< row << " oldcol " << column << " newRow " << newRow << " newCol " << newCol << endl;
		while (newRow < 8 && newRow >= 0 && newCol < 8 && newCol >= 0) {
			if (squareStatus(newCol, newRow) == 'e') {// square is empty
				legalMove[newCol][newRow] = 1;
			}
			else if (squareStatus(newCol, newRow) == 'o') {//square has oppoonent's piece on it
				legalMove[newCol][newRow] = 0;
				return;
			}
			else if (squareStatus(newCol, newRow) == 'k') {//square has oppoonent's king on it
				legalMove[newCol][newRow] = 0;
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
	void pawn::pawnTakingSight(int vectorCol, int vectorRow, int maxDist) {
		int newRow, newCol, iter = 1;
		newRow = row + (vectorRow*iter);
		newCol = column + (vectorCol*iter);
		//cout << "oldrow "<< row << " oldcol " << column << " newRow " << newRow << " newCol " << newCol << endl;
		while (newRow < 8 && newRow >= 0 && newCol < 8 && newCol >= 0) {
			if (squareStatus(newCol, newRow) == 'e') {// square is empty
				return;
			}
			else if (squareStatus(newCol, newRow) == 'o') {//square has oppoonent's piece on it
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