#pragma once
#include <iostream>
//#include "board.h"
//#include "gameLogic.h"


using namespace std;

extern int boardSize;
extern int winNumber;
extern bool isPvP;

char selection = ' ';

void gameLoop();
void startGame();

void menu() {
	cout << "Kulko i krzyzyk!" << endl;
	while (boardSize < 3 || boardSize > 20) {
		cout << "\nPodaj rozmiar planszy (min = 3, max = 20): ";
		cin >> boardSize;
	}
	if (boardSize == 3) {
		while (winNumber < 3 || winNumber > boardSize) {
			cout << "\nPodaj liczbe znakow w rzedzie potrzebnych do wygranej (min = 3, max = " << boardSize << "): ";
			cin >> winNumber;
		}
	}
	else {
		while (winNumber < 4 || winNumber > boardSize) {
			cout << "\nPodaj liczbe znakow w rzedzie potrzebnych do wygranej (min = 4, max = " << boardSize << "): ";
			cin >> winNumber;
		}
	}
	
	while (selection != '1' && selection != '2') {
		cout << "\nWybierz tryb gry:\n1. Gracz kontra Gracz\n2. Gracz kontra SI\n";
		cin >> selection;
		if (selection == '1') {
			cout << "\nWybrales tryb Gracz kontra Gracz." << endl;
			isPvP = true;
		}
		else if (selection == '2') {
			cout << "\nWybrales tryb Gracz kontra SI." << endl;
			isPvP = false;
		}
		else {
			cout << "\nNiepoprawny wybór." << endl;
		}
	}
}

void endMenu() {
	char choice = '0';
	while (choice != '1' && choice != '2') {
		cout << "\nKoniec gry!" << endl;
		cout << "1. Zagraj ponownie\n2. Wyjscie\n";
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
			cout << "Dzieki za gre!" << endl;
			deleteBoard(board, boardSize); // Clean up the board memory
			selection = '0'; // Reset selection to exit the loop
			boardSize = 0; // Reset board size
			winNumber = 0; // Reset win number
			isPvP = true; // Reset to default PvP mode
			cout << "Do zobaczenia!" << endl;
			exit(0); // Exit the program
			//return; // Exit the game
		}
		else {
			cout << "Niepoprawny wybor!" << endl;
		}
	}
}