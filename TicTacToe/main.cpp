#include <iostream>
#include "board.h"
#include "gameLogic.h"

using namespace std;

unsigned int boardSize = 0;
unsigned int winNumber = 0;
bool currentPlayer = 0;
bool isPvP = 1;
char gameChars[] = { 'O', 'X' };

unsigned int xPlace = 0, yPlace = 0;

int main() {
	cout << "Welcome to Tic Tac Toe!" << endl;
	while (boardSize < 3 || boardSize > 20) {
		cout << "\nSpecify board size (min = 3, max = 20): ";
		cin >> boardSize;
	}
	while (winNumber < 3 || winNumber > boardSize) {
		cout << "\nSpecify win number (min = 3, max = " << boardSize << "): ";
		cin >> winNumber;
	}
	char** board = createBoard(boardSize);
	printBoard(boardSize, board);
	return 0;
}