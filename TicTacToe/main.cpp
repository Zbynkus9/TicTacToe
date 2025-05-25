#include <iostream>
#include "board.h"
#include "gameLogic.h"

using namespace std;

unsigned int boardSize = 0;
unsigned int winNumber = 0;
bool currentPlayer = 0;
bool isPvP = 1;
bool gameChars[] = { 'O', 'X' };

unsigned int xPlace = 0, yPlace = 0;

int main() {
	cout << "Welcome to Tic Tac Toe!" << endl;
	while (boardSize < 3 || boardSize > 20) {
		cout << "Specify board size (min = 3, max = 20): ";
		cin >> boardSize;
	}
	char** board = createBoard(4);
	printBoard(4, board);
	return 0;
}