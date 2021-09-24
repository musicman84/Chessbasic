# chessBasic
Simple 2 player chess game.
Rules implemented are:
*Player turn taking
*Pieces cannot move onto pieces of the same colour
*Moving a piece onto a space occupied by an opponents piece removes the opponents piece from the game

Instructions to play:
*On startup, enter number of players (has to be 2)
*Select view of board (from white's view or black's) {Dev note- could added dynamic view option - view from player whose turn it is}
#Board will then be displayerd. 'ee' is an empty space, 'W' or 'B' first letter specifies that the piece is white or black respectively
#second letter specifes the piece as:
    p = pawn
    r = rook
    n = knight
    b = bishop
    k = king
    q = queen
*Player 1's turn (white pieces) - select piece to move by cooardinates (coloumn letter, row number) for example A2, then select piece destination using the same coordinates system
*Player 2's turn (black pieces) - see above
*close window to end (checkmate is not yet implemented)

To run executable, the StandardBoardInit.dat file must be within the same folder.
