#pragma once
#include <iostream>
#include "linkedList.h"
//#include <Windows.h>

//system("cls");

using namespace std;
//do miany przekazanie board

extern bool currentPlayer;
extern char gameChars[];
extern unsigned int boardSize;
extern unsigned int winNumber;
extern unsigned int xPlace, yPlace;


void winCheck(unsigned int size, unsigned int winNum, char** &board, char currentChar, unsigned int x_place, unsigned int y_place) {
	SLinkedList winCheckList;
	//Check row
	winCheckList.addOnEmpty(board[x_place][y_place]);
	for (unsigned int i = 1; i < winNum; i++) {
		if (x_place + i < size) {
			winCheckList.addBack(board[x_place + i][y_place]);
		}
		if (x_place - i >= 0) {
			winCheckList.addFront(board[x_place - i][y_place]);
		}
	}
	if (winCheckList.getSize() < winNum) {
		winCheckList.clearList(); // Not enough elements to check for a win
	}
	else {
		unsigned int count = 0;
		SNode* current = winCheckList.getHead();
		for (unsigned int i = 0; i < winCheckList.getSize(); i++) {
			if (current->getValue() == currentChar) {
				count++;
			}
			else {
				count = 0;
			}

			current = current->getNext();

			if (count >= winNum) {
				cout << "Player " << currentChar << " wins!" << endl;
				return;
			}
		}
		winCheckList.clearList(); // Clear the list after checking
	}
	//Check column
	winCheckList.addOnEmpty(board[x_place][y_place]);
	for (unsigned int i = 1; i < winNum; i++) {
		if (y_place + i < size) {
			winCheckList.addBack(board[x_place][y_place + i]);
		}
		if (y_place - i >= 0) {
			winCheckList.addFront(board[x_place][y_place - i]);
		}
	}
	if (winCheckList.getSize() < winNum) {
		winCheckList.clearList(); // Not enough elements to check for a win
	}
	else {
		unsigned int count = 0;
		SNode* current = winCheckList.getHead();
		for (unsigned int i = 0; i < winCheckList.getSize(); i++) {
			if (current->getValue() == currentChar) {
				count++;
			}
			else {
				count = 0;
			}

			current = current->getNext();

			if (count >= winNum) {
				cout << "Player " << currentChar << " wins!" << endl;
				return;
			}
		}
		winCheckList.clearList(); // Clear the list after checking
	}
	//Check diagonal rising
	winCheckList.addOnEmpty(board[x_place][y_place]);
	for (unsigned int i = 1; i < winNum; i++) {
		if (x_place + i < size && y_place + i < size) {
			winCheckList.addBack(board[x_place + i][y_place + i]);
		}
		if (x_place - i >= 0 && y_place - i >= 0) {
			winCheckList.addFront(board[x_place - i][y_place - i]);
		}
	}
	if (winCheckList.getSize() < winNum) {
		winCheckList.clearList(); // Not enough elements to check for a win
	}
	else {
		unsigned int count = 0;
		SNode* current = winCheckList.getHead();
		for (unsigned int i = 0; i < winCheckList.getSize(); i++) {
			if (current->getValue() == currentChar) {
				count++;
			}
			else {
				count = 0;
			}

			current = current->getNext();

			if (count >= winNum) {
				cout << "Player " << currentChar << " wins!" << endl;
				return;
			}
		}
		winCheckList.clearList(); // Clear the list after checking
	}
	//Check diagonal falling
	winCheckList.addOnEmpty(board[x_place][y_place]);
	for (unsigned int i = 1; i < winNum; i++) {
		if (x_place + i < size && y_place - i >= 0) {
			winCheckList.addBack(board[x_place + i][y_place - i]);
		}
		if (x_place - i >= 0 && y_place + i < size) {
			winCheckList.addFront(board[x_place - i][y_place + i]);
		}
	}
	if (winCheckList.getSize() < winNum) {
		winCheckList.clearList(); // Not enough elements to check for a win
	}
	else {
		unsigned int count = 0;
		SNode* current = winCheckList.getHead();
		for (unsigned int i = 0; i < winCheckList.getSize(); i++) {
			if (current->getValue() == currentChar) {
				count++;
			}
			else {
				count = 0;
			}

			current = current->getNext();

			if (count >= winNum) {
				cout << "Player " << currentChar << " wins!" << endl;
				return;
			}
		}
	}
	winCheckList.clearList(); // Clear the list after checking
}

void changePlayer() {
	currentPlayer = currentPlayer; // Switch between players
}

void placeChar(unsigned int x_place, unsigned int y_place, char**& board) {
	bool isMoveValid = false;
	while (!isMoveValid) {
		if (board[x_place][y_place] == ' ') {
			board[x_place][y_place] = gameChars[currentPlayer];
			winCheck(boardSize, winNumber, board, gameChars[currentPlayer], x_place, y_place);
			changePlayer();
			isMoveValid = true;
		}
		else {
			cout << "\nThis place is already taken!" << endl;
		}
	}
}