#pragma once
#include <iostream>
#include <Windows.h>


using namespace std;
//do miany przekazanie board
void printBoard(unsigned int size, char** &board) {
	system("cls");
	unsigned int x_size = (6 * size) -1;
	unsigned int y_size = (4 * size) -1;
	for (unsigned int j = 0; j < y_size; j++) {
		for (unsigned int i = 0; i < x_size; i++) {
			if ((i + 1) % 6 == 3 && (j + 1) % 4 == 2) {
				cout << board[j / 4][i / 6];
				//cout << "Z";
			}
			else if (i > 0 && (i + 1) % 6 == 0) {
				cout << "|";
			}
			else if (j > 0 && (j + 1) % 4 == 0 && ((i + 1) % 6 == 1 || (i + 1) % 6 == 3 || (i + 1) % 6 == 5)) {
				cout << "-";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

void initBoard(unsigned int size, char**& board) {
	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < size; j++) {
			board[i][j] = ' ';
		}
	}
}
char** createBoard(unsigned int size) {
	char** board = new char* [size];
	for (unsigned int i = 0; i < size; i++) {
		board[i] = new char[size];
	}
	initBoard(size, board);
	return board;
}

void deleteBoard(char**& board, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		delete[] board[i];
	}
	delete[] board;
	board = nullptr;
}
