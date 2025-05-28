#pragma once
#include <iostream>
#include "linkedList.h"
//#include "menu.h"
//#include "board.h"
//#include <Windows.h>

//system("cls");

using namespace std;

void menu();
void endMenu();

//do miany przekazanie board

extern bool currentPlayer;
extern char gameChars[];
extern unsigned int boardSize;
extern unsigned int winNumber;
extern long int xPlace, yPlace;
extern char** board;
extern bool isPvP; // Player vs Player mode

unsigned int elementsOnBoard = 0; // Counter for the number of elements on the board
unsigned int maxElementsOnBoard = 99; // Maximum number of elements on the board


bool winCheck(unsigned int size, unsigned int winNum, char** &board, char currentChar, long int x_place, long int y_place) {
	SLinkedList winCheckList;
	cout << "\nCol: ";
	//Check Column
	winCheckList.addOnEmpty(board[x_place][y_place]);
	for (long int i = 1; i < winNum; i++) {
		if (x_place + i < size) {
			winCheckList.addBack(board[x_place + i][y_place]);
		}
		if (x_place - i >= 0) {
			winCheckList.addFront(board[x_place - i][y_place]);
		}
	}
	if (winCheckList.getSize() < winNum) {
		winCheckList.clearList(); // Not enough elements to check for a win
		cout << "Not enough elements to check for a win." << endl;
	}
	else {
		unsigned int count = 0;
		SNode* current = winCheckList.getHead();
		for (unsigned int i = 0; i < winCheckList.getSize(); i++) {
			cout << current->getValue() << " ; ";
			if (current->getValue() == currentChar) {
				count++;
			}
			else {
				count = 0;
			}

			current = current->getNext();

			if (count >= winNum) {
				//cout << "Player " << currentChar << " wins!" << endl;
				winCheckList.clearList(); // Clear the list after checking
				//wyswietl plansze, powiedz kto wygra³ i zakoñcz grê dajac menu z wyborem co dalej
				return true;
			}
		}
		cout << endl;
		winCheckList.clearList(); // Clear the list after checking
	}
	//Check row
	cout << "\nRow: ";
	winCheckList.addOnEmpty(board[x_place][y_place]);
	for (long int i = 1; i < winNum; i++) {
		if (y_place + i < size) {
			winCheckList.addBack(board[x_place][y_place + i]);
		}
		if (y_place - i >= 0) {
			winCheckList.addFront(board[x_place][y_place - i]);
		}
	}
	if (winCheckList.getSize() < winNum) {
		winCheckList.clearList(); // Not enough elements to check for a win
		cout << "Not enough elements to check for a win." << endl;
	}
	else {
		unsigned int count = 0;
		SNode* current = winCheckList.getHead();
		for (unsigned int i = 0; i < winCheckList.getSize(); i++) {
			cout << current->getValue() << " ; ";
			if (current->getValue() == currentChar) {
				count++;
			}
			else {
				count = 0;
			}

			current = current->getNext();

			if (count >= winNum) {
				//cout << "Player " << currentChar << " wins!" << endl;
				winCheckList.clearList(); // Clear the list after checking
				//wyswietl plansze, powiedz kto wygra³ i zakoñcz grê dajac menu z wyborem co dalej
				return true;
			}
		}
		cout << endl;
		winCheckList.clearList(); // Clear the list after checking
	}
	//Check diagonal falling
	cout << "\nDiag f: ";
	winCheckList.addOnEmpty(board[x_place][y_place]);
	for (long int i = 1; i < winNum; i++) {
		if (x_place + i < size && y_place + i < size) {
			winCheckList.addBack(board[x_place + i][y_place + i]);
		}
		if (x_place - i >= 0 && y_place - i >= 0) {
			winCheckList.addFront(board[x_place - i][y_place - i]);
		}
	}
	if (winCheckList.getSize() < winNum) {
		winCheckList.clearList(); // Not enough elements to check for a win
		cout << "Not enough elements to check for a win." << endl;
	}
	else {
		unsigned int count = 0;
		SNode* current = winCheckList.getHead();
		for (unsigned int i = 0; i < winCheckList.getSize(); i++) {
			cout << current->getValue() << " ; ";
			if (current->getValue() == currentChar) {
				count++;
			}
			else {
				count = 0;
			}

			current = current->getNext();

			if (count >= winNum) {
				//cout << "Player " << currentChar << " wins!" << endl;
				winCheckList.clearList(); // Clear the list after checking
				//wyswietl plansze, powiedz kto wygra³ i zakoñcz grê dajac menu z wyborem co dalej
				return true;
			}
		}
		cout << endl;
		winCheckList.clearList(); // Clear the list after checking
	}
	//Check diagonal rising
	cout << "\nDiag r: ";
	winCheckList.addOnEmpty(board[x_place][y_place]);
	for (long int i = 1; i < winNum; i++) {
		if (x_place + i < size && y_place - i >= 0) {
			winCheckList.addBack(board[x_place + i][y_place - i]);
		}
		if (x_place - i >= 0 && y_place + i < size) {
			winCheckList.addFront(board[x_place - i][y_place + i]);
		}
	}
	if (winCheckList.getSize() < winNum) {
		winCheckList.clearList(); // Not enough elements to check for a win
		cout << "Not enough elements to check for a win." << endl;
	}
	else {
		unsigned int count = 0;
		SNode* current = winCheckList.getHead();
		for (unsigned int i = 0; i < winCheckList.getSize(); i++) {
			cout << current->getValue() << " ; ";
			if (current->getValue() == currentChar) {
				count++;
			}
			else {
				count = 0;
			}

			current = current->getNext();

			if (count >= winNum) {
				//cout << "Player " << currentChar << " wins!" << endl;
				winCheckList.clearList(); // Clear the list after checking
				//wyswietl plansze, powiedz kto wygra³ i zakoñcz grê dajac menu z wyborem co dalej
				return true;
			}
		}
	}
	cout << endl;
	winCheckList.clearList(); // Clear the list after checking
	return false; // No win found
}

void changePlayer() {
	currentPlayer = !currentPlayer; // Switch between players
}

bool makeMove(long int x_place, long int y_place, char**& board) {	
	if (board[x_place][y_place] == ' ') { //infinite loop bug
		board[x_place][y_place] = gameChars[currentPlayer];
		elementsOnBoard++;
		return true;
	}
	else {
		cout << "\nThis place is already taken!" << endl;
		return false;
	}
}

void setMaxElementsOnBoard() {
	maxElementsOnBoard = boardSize * boardSize; // Maximum elements on the board
}

bool checkForDraw() {
	if (elementsOnBoard == maxElementsOnBoard) {
		cout << "It's a draw!" << endl;
		return true;
	}
	return false; // Not a draw
}

void startGame() {
	menu();
	board = createBoard(boardSize);
	if (!board) {
		cerr << "Error: Unable to create board." << endl;
		return;
	}
	setMaxElementsOnBoard();
}

void gameLoop() {
	switch (isPvP)
	{
	case 0: // Player vs AI
		cout << "AI mode is not implemented yet." << endl;
		deleteBoard(board, boardSize);
		return;
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

			if (winCheck(boardSize, winNumber, board, gameChars[currentPlayer], xPlace - 1, yPlace - 1)) {
				printBoard(boardSize, board);
				cout << "Player " << gameChars[currentPlayer] << " wins!" << endl;
				elementsOnBoard = 0; // Reset the counter for the next game
				deleteBoard(board, boardSize);
				endMenu();
				//break;
			}

			//Sleep(2000);

			changePlayer();

			if (checkForDraw()) {
				printBoard(boardSize, board);
				cout << "It's a draw!" << endl;
				elementsOnBoard = 0;
				deleteBoard(board, boardSize);
				break;
			}

			printBoard(boardSize, board);

		}
		break;

	default:
		break;
	}
}