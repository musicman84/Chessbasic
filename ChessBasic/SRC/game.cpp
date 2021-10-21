#include "game.h"
	game::game()
	{
		board cBoard;
		cBoard.loadBoard();//load initial board setup
		//input is read in as a character (rather than int)
		cout << "Number of players (0/1/2) = \n";
		cin >> numPchaArr;
		numPcha = numPchaArr[0];
		while (numPcha != '0' && numPcha != '1' && numPcha != '2')
		{
			numPchaArr[0] = '0';
			cout << "Invalid answer" << endl;
			cout << "Number of players (0/1/2) = \n";
			cin >> numPchaArr;
			numPcha = numPchaArr[0];
		}
		if (numPcha != '2') {//remove once AI implemented
			cout << "Only two player implemented" << endl;
			numPcha = '2';
		}


		if (numPcha == '1')
		{
			cout << "Choose colour (w/b) = \n";

			cin >> pColourArr;
			pColour = pColourArr[0];
			while (pColour != 'w' && pColour != 'b')
			{
				cout << "Invalid answer" << endl;
				cout << "Choose colour (w/b) = \n";
				cin >> pColourArr;
				pColour = pColourArr[0];
			}
		}

		cout << "Choose view (w/b) = \n";
		cin >> viewArr;
		view = viewArr[0];
		while (view != 'w' && view != 'b')
		{
			cout << "Invalid answer" << endl;
			cout << "Choose view (w/b) = \n";
			cin >> viewArr;
			view = viewArr[0];
		}
		//view = 'w';//SET FOR NOW

		//Turn array definition
		if (numPcha == '2')
		{
			turn[0] = new human{ cBoard.getWhitePieces(),cBoard.getWhitePieceCount(),cBoard.getBlackPieces(),cBoard.getBlackPieceCount(),"player1" };
			turn[1] = new human{ cBoard.getBlackPieces(),cBoard.getBlackPieceCount(),cBoard.getWhitePieces(),cBoard.getWhitePieceCount(),"player2" };
			//cout << "CASE A" << endl;
		}

		else if (numPcha == '1')
		{
			if (pColour == 'w')
			{
				turn[0] = new human{ cBoard.getWhitePieces(),cBoard.getWhitePieceCount(),cBoard.getBlackPieces(),cBoard.getBlackPieceCount(),"player1" };
				turn[1] = new AI{ cBoard.getBlackPieces(),cBoard.getBlackPieceCount(),cBoard.getWhitePieces(),cBoard.getWhitePieceCount(),"AI2" };
				//cout << "CASE B" << endl;
			}

			else if (pColour == 'b')
			{
				turn[0] = new AI{ cBoard.getWhitePieces(),cBoard.getWhitePieceCount(),cBoard.getBlackPieces(),cBoard.getBlackPieceCount(),"AI1" };
				turn[1] = new human{ cBoard.getBlackPieces(),cBoard.getBlackPieceCount(),cBoard.getWhitePieces(),cBoard.getWhitePieceCount(),"player2" };
				//cout << "CASE C" << endl;
			}

			else
			{
				cout << "switching error";
				exit(1);
			}
		}
		else if (numPcha == '0')
		{
			turn[0] = new AI{ cBoard.getWhitePieces(),cBoard.getWhitePieceCount(),cBoard.getBlackPieces(),cBoard.getBlackPieceCount(),"AI1" };
			turn[1] = new AI{ cBoard.getBlackPieces(),cBoard.getBlackPieceCount(),cBoard.getWhitePieces(),cBoard.getWhitePieceCount(),"AI2" };
			//cout << "CASE D"<<endl;
		}
		else
		{
			cout << "switching error";
			exit(1);

		}
		cBoard.setBoard();//update board (remove invisible pieces)
		cBoard.printBoard(view);

		while (!checkMate)//run until checkmate
		{
			int i = turnCount % 2;//alternate i between 0 and 1
			turnCount++;//track number of turns
			checkMate = turn[i]->initialCalcsShowCheckMate();
			if (!checkMate) {
				turn[i]->takeTurn();//player takes turn
				cBoard.setBoard();//update board
				cBoard.printBoard(view);//show updated board
			}
			
		}
	};
	game::~game() {//destructor - deallocate dynamic memory
		for (int i = 0; i < 2; i++) {
			delete turn[i];
		}
	}