#include <iostream>
#include "board.h"
#include "gameLogic.h"
#include "menu.h"

using namespace std;

unsigned int boardSize = 0;
unsigned int winNumber = 0;
bool currentPlayer = 0;
bool isPvP = 1;
char gameChars[] = { 'O', 'X' };
string menuSelection = "";

long int xPlace = 0, yPlace = 0; //powinny byc na odwrot wiersze i kolumny

int main() {
	menu();
	char** board = createBoard(boardSize);
	if (!board) {
		cerr << "Error: Unable to create board." << endl;
		return 1;
	}
	setMaxElementsOnBoard();
	switch (isPvP)
	{
	case 0: // Player vs AI
		cout << "AI mode is not implemented yet." << endl;
		deleteBoard(board, boardSize);
		return 0;
		break;

	case 1: // Player vs Player
		printBoard(boardSize, board);
		while (true) {
			cout << "Player " << gameChars[currentPlayer] << ", enter your move (row and column): ";
			cin >> xPlace >> yPlace;
			if (yPlace < 1 || yPlace > boardSize || xPlace < 1 || xPlace > boardSize) {
				cout << "Invalid move. Please try again." << endl;
				continue;
			}

			if (!makeMove(xPlace - 1, yPlace - 1, board)) {
				continue;
			} 

			winCheck(boardSize, winNumber, board, gameChars[currentPlayer], xPlace - 1, yPlace - 1);

			Sleep(5000);

			changePlayer();

			if (checkForDraw()) {
				printBoard(boardSize, board);
				cout << "It's a draw!" << endl;
				break;
			}

			printBoard(boardSize, board);

		}
		break;

	default:
		break;
	}
	return 0;
}