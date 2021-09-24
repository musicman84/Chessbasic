#include "human.h"
	human::human(piece** ownPiecesPar, int ownPieceCountPar, piece** oppPiecesPar, int oppPieceCountPar, string Name)
		:player(ownPiecesPar, ownPieceCountPar, oppPiecesPar, oppPieceCountPar, Name) {};
	void human::takeTurn() {
		cout << name << " to play" << endl;

		cout << "Enter coordinate of piece to move (let,num):";
		cin >> coordStart;

		colStart = convertColCoord(coordStart.substr(0, 1));
		rowStart = convertRowCoord(coordStart.substr(1, 1));
		while (!this->checkCoordOwnPiece(colStart, rowStart)) {//do until coordinate matchs with own piece
			cout << "Invalid choice\n";
			cout << "Enter coordinate of piece to move (let,num):";
			cin >> coordStart;

			colStart = convertColCoord(coordStart.substr(0, 1));
			rowStart = convertRowCoord(coordStart.substr(1, 1));
		}


		cout << "Enter coordinate of piece destination (let,num):";
		cin >> coordFinish;
		colFinish = convertColCoord(coordFinish.substr(0, 1));
		rowFinish = convertRowCoord(coordFinish.substr(1, 1));
		while (!this->checkDestLocation(colFinish, rowFinish)) {
			cout << "Invalid choice\n";
			cout << "Enter coordinate of piece destination (let,num):";
			cin >> coordFinish;
			colFinish = convertColCoord(coordFinish.substr(0, 1));
			rowFinish = convertRowCoord(coordFinish.substr(1, 1));
		}

		cout << endl;//print empty line
		(this->findPieceFromCoord(colStart, rowStart))->movePieceTo(colFinish, rowFinish);//move piece
	};

	bool human::checkDestLocation(int col, int row) {//return true if move is on board and not own piece
		bool flag = false;
		//check destination is on the board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (col == i && row == j) {
					flag = true;
				}
			}
		}
		//check destination doesn't contain own piece
		for (int i = 0; i < ownPieceCount; i++)
			if ((*ownPieces[i]).getColumn() == col && (*ownPieces[i]).getRow() == row) {
				flag = false;
			}
		

		//check if destination contains opponent's piece
		for (int i = 0; i < oppPieceCount; i++)
			if ((*oppPieces[i]).getColumn() == col && (*oppPieces[i]).getRow() == row) {
				//(*oppPieces[i]).;
				cout << "take piece/n";
				takePiece(oppPieces[i], i);
			}
		return flag;
	}

	bool human::checkCoordOwnPiece(int col, int row) {//check user input coordinate is location of own piece
		for (int i = 0; i < ownPieceCount; i++)
			if ((*ownPieces[i]).getColumn() == col && (*ownPieces[i]).getRow() == row) {
				return true;
			}
		return false;
	}

	piece* human::findPieceFromCoord(int col, int row) {//check user input coordinate is location of own piece
		for (int i = 0; i < ownPieceCount; i++)
			if ((*ownPieces[i]).getColumn() == col && (*ownPieces[i]).getRow() == row) {
				return ownPieces[i];
			}
		exit(8);
	}

	int human::convertColCoord(string original)//converts A=0, B=1 etc
	{

		string const letArray[] = { "A","B","C","D","E","F","G","H" };
		string const letArrayLowCase[] = { "a","b","c","d","e","f","g","h" };
		for (int i = 0; i < (sizeof(letArray) / sizeof(letArray[0])); i++) {
			if (original == letArray[i] || original == letArrayLowCase[i]) {
				return (i);
			}
		}
		return 9;
	}

	int human::convertRowCoord(string original)//converts "0"=0, "1"=1 etc
	{
		string const numArray[] = { "1","2","3","4","5","6","7","8" };
		for (int i = 0; i < (sizeof(numArray) / sizeof(numArray[0])); i++) {
			if (original == numArray[i]) {
				return (i);
			}
		}
		return 9;
	}