#pragma once
#include <iostream>

using namespace std;

extern unsigned int boardSize;
extern unsigned int winNumber;
extern bool isPvP;

char selection = ' ';

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