#pragma once
#include "player.h"
struct AImove {
	AImove(piece* movingPieceArg, int moveToColArg, int moveToRowArg);
	piece* movingPiece;
	int moveToCol;
	int moveToRow;
};