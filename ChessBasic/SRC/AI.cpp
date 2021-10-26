#include "AI.h"
//for random only
#include <cstdlib> 
#include <ctime>
//end for random only
	AI::AI(piece** ownPiecesPar, int ownPieceCountPar, piece** oppPiecesPar, int oppPieceCountPar, string Name)
		:player(ownPiecesPar, ownPieceCountPar, oppPiecesPar, oppPieceCountPar, Name) {};
	void AI::takeTurn() {
		numberOfPosMoves = 0;
		AllPossMovesForAI.clear(); //clear vector using standard vector method
		for (int i = 0; i < ownPieceCount; i++) {
			if (!ownPieces[i]->getIsPieceTaken()) {
				for (int j = 0; j < 8; j++) {
					for (int k = 0; k < 8; k++) {
						if (ownPieces[i]->isMoveLegal(j, k)) {
							AllPossMovesForAI.push_back(AImove(ownPieces[i], j, k));
							numberOfPosMoves++;
						}
					}
				}
			}
		}
		//random- start
		srand(static_cast<unsigned int>(time(nullptr)));
		int randMoveNum = (rand() % numberOfPosMoves);// mod taken to bring random numbers into range
		//random finish
		AImove moveP = AllPossMovesForAI[randMoveNum];
		moveP.movingPiece->movePieceTo(moveP.moveToCol,moveP.moveToRow);//make move
		(*ownPieces)->clearAllLegalMoveArrays();//clear outdated legal move arrays (all pieces)
	};
//random move is chosen
	string AI::getPlayerType() {
		return("ai");
	}