#pragma once
#include <iostream>
#include <algorithm>
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
extern int boardSize;
extern int winNumber;
extern long int xPlace, yPlace;
extern char** board;
extern bool isPvP; // Player vs Player mode
extern int depth; // Depth for AI

unsigned int elementsOnBoard = 0; // Counter for the number of elements on the board
unsigned int maxElementsOnBoard = 99; // Maximum number of elements on the board


bool winCheck(int size, int winNum, char** &board, char currentChar, long int x_place, long int y_place) {
	SLinkedList winCheckList;
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
	}
	else {
		int count = 0;
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
				winCheckList.clearList(); // Clear the list after checking
				//wyswietl plansze, powiedz kto wygra³ i zakoñcz grê dajac menu z wyborem co dalej
				return true;
			}
		}
		winCheckList.clearList(); // Clear the list after checking
	}
	//Check row
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
	}
	else {
		int count = 0;
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
				winCheckList.clearList(); // Clear the list after checking
				//wyswietl plansze, powiedz kto wygra³ i zakoñcz grê dajac menu z wyborem co dalej
				return true;
			}
		}
		winCheckList.clearList(); // Clear the list after checking
	}
	//Check diagonal falling
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
	}
	else {
		int count = 0;
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
				winCheckList.clearList(); // Clear the list after checking
				//wyswietl plansze, powiedz kto wygra³ i zakoñcz grê dajac menu z wyborem co dalej
				return true;
			}
		}
		winCheckList.clearList(); // Clear the list after checking
	}
	//Check diagonal rising
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
	}
	else {
		int count = 0;
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
				winCheckList.clearList(); // Clear the list after checking
				//wyswietl plansze, powiedz kto wygra³ i zakoñcz grê dajac menu z wyborem co dalej
				return true;
			}
		}
	}
	winCheckList.clearList(); // Clear the list after checking
	return false; // No win found
}


bool isWin(char player) {
	for (int i = 0; i < boardSize; ++i)
		for (int j = 0; j < boardSize; ++j)
			if (board[i][j] == player && winCheck(boardSize, winNumber, board, player, i, j))
				return true;
	return false;
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
		cout << "\nTo miejsce jest juz zajete!" << endl;
		return false;
	}
}

void setMaxElementsOnBoard() {
	maxElementsOnBoard = boardSize * boardSize; // Maximum elements on the board
}

bool checkForDraw() {
	if (elementsOnBoard == maxElementsOnBoard) {
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

//ocenia wartoœæ pojedynczej linii na planszy. Linia mo¿e byæ wierszem, kolumn¹ lub przek¹tn¹. Ocenia ona, ile symboli danego gracza oraz przeciwnika znajduje siê w tej linii i na tej podstawie przyznaje punkty.
int ocenLinie(char gracz, int start_wiersz, int start_kolumna, int kierunek_wiersz, int kierunek_kolumna) {
	int liczba_gracza = 0;
	int liczba_przeciwnika = 0;
	char przeciwnik = (gracz == gameChars[1]) ? gameChars[0] : gameChars[1];

	for (int k = 0; k < winNumber; ++k) {
		char komorka = board[start_wiersz + k * kierunek_wiersz][start_kolumna + k * kierunek_kolumna];
		if (komorka == gracz) {
			liczba_gracza++;
		}
		else if (komorka == przeciwnik) {
			liczba_przeciwnika++;
		}
	}

	if (liczba_gracza == winNumber - 1 && liczba_przeciwnika == 0)
		return 50; // almost winning
	if (liczba_przeciwnika == winNumber - 1 && liczba_gracza == 0)
		return -100; // block opponent


	if (liczba_gracza > 0 && liczba_przeciwnika == 0) {
		return liczba_gracza;
	}
	else if (liczba_przeciwnika > 0 && liczba_gracza == 0) {
		return -liczba_przeciwnika;
	}
	else {
		return 0;
	}
}

int ocena() {
	int wynik = 0;

	for (int i = 0; i < boardSize; ++i) {
		for (int j = 0; j <= boardSize - winNumber; ++j) {
			wynik += ocenLinie(gameChars[1], i, j, 0, 1);
			wynik -= ocenLinie(gameChars[0], i, j, 0, 1);
			wynik += ocenLinie(gameChars[1], j, i, 1, 0);
			wynik -= ocenLinie(gameChars[0], j, i, 1, 0);
		}
	}

	for (int i = 0; i <= boardSize - winNumber; ++i) {
		for (int j = 0; j <= boardSize - winNumber; ++j) {
			wynik += ocenLinie(gameChars[1], i, j, 1, 1);
			wynik -= ocenLinie(gameChars[0], i, j, 1, 1);
			wynik += ocenLinie(gameChars[1], i, j + winNumber - 1, 1, -1);
			wynik -= ocenLinie(gameChars[0], i, j + winNumber - 1, 1, -1);
		}
	}

	return wynik;
}

int minimax(int glebokosc, int alpha, int beta, bool maksymalizowanie) {
	if (isWin(gameChars[1])) return 10 - glebokosc;
	if (isWin(gameChars[0])) return glebokosc - 10;
	if (checkForDraw()) return 0;
	if (glebokosc >= depth) return ocena();

	if (maksymalizowanie) {
		int najlepszy = -1000000;
		for (int i = 0; i < boardSize; ++i) {
			for (int j = 0; j < boardSize; ++j) {
				if (board[i][j] == ' ') {
					board[i][j] = gameChars[1];
					elementsOnBoard++;
					int wartosc = minimax(glebokosc + 1, alpha, beta, false);
					board[i][j] = ' ';
					elementsOnBoard--;
					najlepszy = max(najlepszy, wartosc);
					alpha = max(alpha, najlepszy);
					if (beta <= alpha) break;
				}
			}
		}
		return najlepszy;
	}
	else {
		int najlepszy = 1000000;
		for (int i = 0; i < boardSize; ++i) {
			for (int j = 0; j < boardSize; ++j) {
				if (board[i][j] == ' ') {
					board[i][j] = gameChars[0];
					elementsOnBoard++;
					int wartosc = minimax(glebokosc + 1, alpha, beta, true);
					board[i][j] = ' ';
					elementsOnBoard--;
					najlepszy = min(najlepszy, wartosc);
					beta = min(beta, najlepszy);
					if (beta <= alpha) break;
				}
			}
		}
		return najlepszy;
	}
}



void ruchSI() {
	int najlepszy_wynik = -1000000;
	int ruch_wiersz = -1;
	int ruch_kolumna = -1;

	for (int i = 0; i < boardSize; ++i) {
		for (int j = 0; j < boardSize; ++j) {
			if (board[i][j] == ' ') {
				board[i][j] = gameChars[1];
				elementsOnBoard++;
				int ruch_wynik = minimax(0, -1000000, 1000000, false);
				board[i][j] = ' ';
				elementsOnBoard--;

				if (ruch_wynik > najlepszy_wynik) {
					najlepszy_wynik = ruch_wynik;
					ruch_wiersz = i;
					ruch_kolumna = j;
				}
			}
		}
	}

	makeMove(ruch_wiersz, ruch_kolumna, board);
	xPlace = ruch_wiersz + 1;
	yPlace = ruch_kolumna + 1;
}


void gameLoop() {
	switch (isPvP)
	{
	case 0: // Player vs AI
		depth = 0; // Initialize depth for AI
		while (depth < 1) {
			cout << "Podaj maksymalna glebokosc rekursji dla SI (zalecane 6-9 dla planszy 3x3, 4-6 dla wiekszych plansz): ";
			cin >> depth;
		}

		printBoard(boardSize, board);
		// Reset the game board and player variables
		xPlace = 0;
		yPlace = 0;
		currentPlayer = 0; // Start with player 1
		elementsOnBoard = 0; // Reset the counter for the number of elements on the board
		while (true) {
			cout << "Gracz " << gameChars[0] << ", wprowadz swoj ruch (rzad i kolumna): ";
			cin >> xPlace >> yPlace;
			if (yPlace < 1 || yPlace > boardSize || xPlace < 1 || xPlace > boardSize) {
				cout << "Nieprawidlowy ruch. Sprobuj ponownie." << endl;
				continue;
			}

			if (!makeMove(xPlace - 1, yPlace - 1, board)) {
				continue;
			}

			if (winCheck(boardSize, winNumber, board, gameChars[0], xPlace - 1, yPlace - 1)) {
				printBoard(boardSize, board);
				cout << "Gracz " << gameChars[0] << " Wygrywa!" << endl;
				elementsOnBoard = 0; // Reset the counter for the next game
				deleteBoard(board, boardSize);
				endMenu();
			}


			if (checkForDraw()) {
				printBoard(boardSize, board);
				cout << "Remis!" << endl;
				elementsOnBoard = 0;
				deleteBoard(board, boardSize);
				endMenu();
			}

			changePlayer();

			cout << "Ruch SI..." << endl;

			ruchSI(); // Function to handle AI move
			if (winCheck(boardSize, winNumber, board, gameChars[1], xPlace - 1, yPlace - 1)) {
				printBoard(boardSize, board);
				cout << "Gracz " << gameChars[1] << " Wygrywa!" << endl;
				elementsOnBoard = 0; // Reset the counter for the next game
				deleteBoard(board, boardSize);
				endMenu();
			}
			if (checkForDraw()) {
				printBoard(boardSize, board);
				cout << "Remis!" << endl;
				elementsOnBoard = 0;
				deleteBoard(board, boardSize);
				endMenu();
			}
			xPlace = 0;
			yPlace = 0;
			changePlayer();
			printBoard(boardSize, board);

		}

		break;

	case 1: // Player vs Player
		printBoard(boardSize, board);
		// Reset the game board and player variables
		xPlace = 0;
		yPlace = 0;
		currentPlayer = 0; // Start with player 1
		elementsOnBoard = 0; // Reset the counter for the number of elements on the board
		while (true) {
			cout << "Gracz " << gameChars[currentPlayer] << ", wprowadz swoj ruch (rzad i kolumna): ";
			cin >> xPlace >> yPlace;
			if (yPlace < 1 || yPlace > boardSize || xPlace < 1 || xPlace > boardSize) {
				cout << "Nieprawidlowy ruch. Sprobuj ponownie." << endl;
				continue;
			}

			if (!makeMove(xPlace - 1, yPlace - 1, board)) {
				continue;
			}

			if (winCheck(boardSize, winNumber, board, gameChars[currentPlayer], xPlace - 1, yPlace - 1)) {
				printBoard(boardSize, board);
				cout << "Gracz " << gameChars[currentPlayer] << " Wygrywa!" << endl;
				elementsOnBoard = 0; // Reset the counter for the next game
				deleteBoard(board, boardSize);
				endMenu();
			}


			changePlayer();

			if (checkForDraw()) {
				printBoard(boardSize, board);
				cout << "Remis!" << endl;
				elementsOnBoard = 0;
				deleteBoard(board, boardSize);
				endMenu();
			}

			printBoard(boardSize, board);

		}
		break;
	}
}