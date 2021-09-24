
#include "board.h"

using namespace std;
	board::board() {
	};

	board::~board() {//destructor - deallocate dynamic memory
		for (int i = 0; i < 32; i++) {
			delete allPieces[i];
		}
	}
	void board::setBoard() {//Update board for display
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				boardStr[i][j] = "ee";
			}
		}
		for (int i = 0; i < whitePieceNum; i++) {
			//cout << whitePieces[i]->getVisibility() << endl;
			if (whitePieces[i]->getVisibility()) {
				//cout << whitePieces[i]->getVisibility() << endl;
				string added = "W" + whitePieces[i]->getPieceType();
				boardStr[whitePieces[i]->getColumn()][whitePieces[i]->getRow()] = added;
			}
		}

		for (int j = 0; j < blackPieceNum; j++) {
			if (blackPieces[j]->getVisibility()) {//check piece is visible
				string added = "B" + blackPieces[j]->getPieceType();
				boardStr[blackPieces[j]->getColumn()][blackPieces[j]->getRow()] = added;
			}
		}

	}
	void board::loadBoard() {
		ifstream file;
		file.open("StandardBoardInit.dat", ios::in);//initialise the board to the standard starting setup
		//file.open("C:\Users\music\source\repos\ChessBasic\ChessBasic\test.txt", ios::in);//using absolute path not working
		//file.open("test.txt", ios::in);
		if (!file) {//check if file is found
			cout << "No such file" << endl;
		}
		else {
			char cha1, cha2, cha3;
			string str;
			int column = 0;
			int row = 7;
			// read input and place pieces in a 2D array (boardStr)
			while (true) {
				str = "";//clear str
				file >> cha1 >> cha2 >> cha3;//read 3 characters (the standard format is assumed)
				str.push_back(cha1);//add cha1 to str
				str.push_back(cha2);//add cha2 to end of str

				if (file.eof()) {//read until end of file
					break;
				}
				boardStr[column][row] = str;
				//ordering input to boardStr
				if (column < 7) {
					column++;
				}
				else {
					column = 0;
				}
				if (cha3 == ';') {
					//cout << endl;
					row--;
				}
			}
		}
		file.close();

		//dynamically create pieces and count them
		for (int col = 0; col <= 7; col++) {
			for (int row = 0; row <= 7; row++) {
				if (boardStr[col][row] != "ee") {//redundant check
					string pieceType = boardStr[col][row].substr(1, 1);
					string pieceColour = boardStr[col][row].substr(0, 1);
					if (pieceType == "p" || "r" || "n" || "b" || "q" || "k") {
						if (pieceType == "p") {
							allPieces[pieceNumber] = new pawn(pieceColour, col, row);
							//allPieces[pieceNumber]->sayHi();
							if (pieceColour == "W") {
								whitePieces[whitePieceNum] = allPieces[pieceNumber];
								//cout << whitePieces[whitePieceNum] << endl;
								whitePieceNum++;
							}
							if (pieceColour == "B") {
								blackPieces[blackPieceNum] = allPieces[pieceNumber];
								blackPieceNum++;
							}
						}
						if (pieceType == "r") {
							allPieces[pieceNumber] = new rook(pieceColour, col, row);
							if (pieceColour == "W") {
								whitePieces[whitePieceNum] = allPieces[pieceNumber];
								whitePieceNum++;
							}
							if (pieceColour == "B") {
								blackPieces[blackPieceNum] = allPieces[pieceNumber];
								blackPieceNum++;
							}
						}
						if (pieceType == "n") {
							allPieces[pieceNumber] = new knight(pieceColour, col, row);
							if (pieceColour == "W") {
								whitePieces[whitePieceNum] = allPieces[pieceNumber];
								whitePieceNum++;
							}
							if (pieceColour == "B") {
								blackPieces[blackPieceNum] = allPieces[pieceNumber];
								blackPieceNum++;
							}
						}
						if (pieceType == "b") {
							allPieces[pieceNumber] = new bishop(pieceColour, col, row);
							if (pieceColour == "W") {
								whitePieces[whitePieceNum] = allPieces[pieceNumber];
								whitePieceNum++;
							}
							if (pieceColour == "B") {
								blackPieces[blackPieceNum] = allPieces[pieceNumber];
								blackPieceNum++;
							}
						}
						if (pieceType == "q") {
							allPieces[pieceNumber] = new queen(pieceColour, col, row);
							if (pieceColour == "W") {
								whitePieces[whitePieceNum] = allPieces[pieceNumber];
								whitePieceNum++;
							}
							if (pieceColour == "B") {
								blackPieces[blackPieceNum] = allPieces[pieceNumber];
								blackPieceNum++;
							}
						}
						if (pieceType == "k") {
							allPieces[pieceNumber] = new king(pieceColour, col, row);
							if (pieceColour == "W") {
								whitePieces[whitePieceNum] = allPieces[pieceNumber];
								whitePieceNum++;
							}
							if (pieceColour == "B") {
								blackPieces[blackPieceNum] = allPieces[pieceNumber];
								blackPieceNum++;
							}
						}

						pieceNumber++;//total number of pieces

						if (pieceNumber > 32) {
							cout << "Too many pieces read on board";
							exit(2);
						}

					}
				}
			}
		}

	};
	/*OLD FORMAT
	void printBoard() {
		for (int j = 7; j >= 0; j--) {
			for (int i = 0; i < 8; i++) {
				//cout << i << j;
				cout << numToLet(i) << j+1 << boardStr[i][j] << " ";
				if (i == 7) {
					cout << endl << endl;
				}
			}
		}
	}
	*/
	
		void board::printBoard(char colour) {
			if (colour == 'w') {
				for (int j = 7; j >= 0; j--) {
					for (int i = 0; i < 8; i++) {
						//cout << i << j;
						if (i == 0) {
							cout << j + 1 << "- ";
						}
						cout << boardStr[i][j] << "  ";
						if (i == 7) {
							cout << endl << endl;
						}
					}
				}
				//add column coordinates
				cout << "   ";
				for (int i = 0; i < 8; i++) {
					cout << numToLet(i) << "-  ";
				}
			}
			else if (colour == 'b') {
				for (int j = 0; j < 8; j++) {
					for (int i = 7; i >= 0; i--) {
						//cout << i << j;
						if (i == 7) {
							cout << j + 1 << "- ";
						}
						cout << boardStr[i][j] << "  ";
						if (i == 0) {
							cout << endl << endl;
						}
					}
				}
				//add column coordinates
				cout << "   ";
				for (int i = 7; i >= 0; i--) {
					cout << numToLet(i) << "-  ";
				}
			}

			cout << endl;
		}
		int board::getPieceCount(){
			return pieceNumber;
		}
		int board::getWhitePieceCount() {
			return whitePieceNum;
		}

		int board::getBlackPieceCount() {
			return blackPieceNum;
		}
		piece** board::getWhitePieces() {
			return whitePieces;
		}
		piece** board::getBlackPieces() {
			return blackPieces;
		}
		char board::numToLet(int original)//convert ints to numbers for output only
		{
			char const numToLet[] = "ABCDEFGH";
			if (original >= 0 && original < sizeof(numToLet) - 1)
			{
				return numToLet[original];
			}
			else exit(4);
		}