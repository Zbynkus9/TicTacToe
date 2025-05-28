#pragma once
#include <iostream>
//#include "board.h"
//#include "gameLogic.h"


using namespace std;

extern unsigned int boardSize;
extern unsigned int winNumber;
extern bool isPvP;

char selection = ' ';

void gameLoop();
void startGame();

void menu() {
	cout << "Welcome to Tic Tac Toe!" << endl;
	while (boardSize < 3 || boardSize > 20) {
		cout << "\nSpecify board size (min = 3, max = 20): ";
		cin >> boardSize;
	}
	while (winNumber < 3 || winNumber > boardSize) {
		cout << "\nSpecify win number (min = 3, max = " << boardSize << "): ";
		cin >> winNumber;
	}
	while (selection != '1' && selection != '2') {
		cout << "\nSelect game mode:\n1. Player vs Player\n2. Player vs AI\n";
		cin >> selection;
		if (selection == '1') {
			cout << "\nYou selected Player vs Player mode." << endl;
			isPvP = true;
		}
		else if (selection == '2') {
			cout << "\nYou selected Player vs AI mode." << endl;
			isPvP = false;
		}
		else {
			cout << "\nInvalid selection, please try again." << endl;
		}
	}
}

void endMenu() {
	char choice = '0';
	while (choice != '1' && choice != '2') {
		cout << "\nGame Over!" << endl;
		cout << "1. Play Again\n2. Exit\n";
		cin >> choice;
		if (choice == '1') {
			boardSize = 0;
			winNumber = 0;
			isPvP = true; // Reset to default PvP mode
			selection = ' ';

			startGame();
			gameLoop(); // Restart the game loop
		}
		else if (choice == '2') {
			cout << "Thank you for playing!" << endl;
			return; // Exit the game
		}
		else {
			cout << "Invalid choice!" << endl;
		}
	}
}