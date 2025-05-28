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
char** board = nullptr; // Pointer to the game board

long int xPlace = 0, yPlace = 0; //powinny byc na odwrot wiersze i kolumny

int main() {
	startGame();
	gameLoop();
	return 0;
}