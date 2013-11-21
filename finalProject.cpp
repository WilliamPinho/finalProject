#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

int size;
int ** board;
int ** boardPlayer1;
int * groupsPlayer1;
int ** boardPlayer2;
int * groupsPlayer2;
bool belong;

void chooseBoardSize () {
	cout << "Enter board size: ";
	cin >> size;
	if (size < 3) {
		cout << "\nThis is an invalid size. Please choose a size strictly greater than 2." << endl;
		chooseBoardSize();
	}
}

void generateBoard () {
	chooseBoardSize();
	board = (int **) calloc (size, sizeof(int *));
	boardPlayer1 = (int **) calloc (size, sizeof(int *));
	groupsPlayer1 = (int *) calloc (size*size/2, sizeof(int));
	boardPlayer2 = (int **) calloc (size, sizeof(int *));
	groupsPlayer2 = (int *) calloc (size*size/2, sizeof(int));
	for (int i = 0; i < size; i++) {
		board[i] = (int *) calloc (size, sizeof(int));
		boardPlayer1[i] = (int *) calloc (size, sizeof(int));
		boardPlayer2[i] = (int *) calloc (size, sizeof(int));
	}
}

void printLogo() {
	cout << "------------------------------------------------------------------------" << endl;
	cout << "-                               Hex Game                               -" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	endl(cout);
}

void printBoard() {
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				string s1 (2*(size - 2), ' ');
 				cout << endl << "       " << s1;
				for (int k = 0; k < size; k++) {
					cout << setw(2) << k+1 << "   ";
				}
				cout << endl << endl << endl;
			}
			cout << setw(3) << i+1 << "   ";
			if (i < size - 1) {
				cout << "  ";
				string s2 (2*(size - i - 2), ' ');
				cout << s2;
			}
			for (int j = 0; j < size; j++)
				switch (board[i][j]) {
					case 0:
						cout  << "O    ";
						break;
					case 1:
						cout << "b    ";
						break;
					default:
						cout << "w    ";
				}
			cout << endl << endl;
		}
		cout << endl;
}

void printBoardPlayer1() {
		cout << endl << endl << endl;
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				string s1 (2*(size - 2), ' ');
 				cout << endl << "       " << s1;
				for (int k = 0; k < size; k++) {
					cout << setw(2) << k+1 << "   ";
				}
				cout << endl << endl << endl;
			}
			cout << setw(3) << i+1 << "   ";
			if (i < size - 1) {
				cout << "  ";
				string s2 (2*(size - i - 2), ' ');
				cout << s2;
			}
			for (int j = 0; j < size; j++)
				cout  << boardPlayer1[i][j] << "    ";
			cout << endl << endl;
		}
		cout << endl;
}

bool isThereAWinner () {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if((boardPlayer1[0][i] == boardPlayer1[size-1][j]) && (boardPlayer1[0][i]*boardPlayer1[size-1][j] != 0)) {
				system ("clear");
				printLogo();
				printBoard();
				printBoardPlayer1();
				cout << "Player 1 wins!" << endl;
				return true;			
			}
			if((boardPlayer2[i][0] == boardPlayer2[j][size-1]) && (boardPlayer2[i][0]*boardPlayer2[j][size-1] != 0)) {
				system ("clear");
				printLogo();
				printBoard();
				printBoardPlayer1();
				cout << "Player 2 wins!" << endl;
				return true;			
			}		
		}
	}
}

void updateB(int i, int j, int m, int n) {
	int groupij = boardPlayer1[i][j];
	int groupmn = boardPlayer1[m][n];
	if(belong) {
		groupsPlayer1[groupmn-1] = 0;
		for(int k = 0; k < size; k++) {
			for(int l = 0; l < size; l++) {
				if(boardPlayer1[k][l] == groupmn)
					boardPlayer1[k][l] = groupij;
			}		
		}
	} else {
		boardPlayer1[i][j] = groupmn;
		belong = true;	
	}
}

void updateW(int i, int j, int m, int n) {
	int groupij = boardPlayer2[i][j];
	int groupmn = boardPlayer2[m][n];
	if(belong) {
		groupsPlayer2[groupmn-1] = 0;
		for(int k = 0; k < size; k++) {
			for(int l = 0; l < size; l++) {
				if(boardPlayer2[k][l] == groupmn)
					boardPlayer2[k][l] = groupij;
			}		
		}
	} else {
		boardPlayer2[i][j] = groupmn;
		belong = true;	
	}
}

void compare(int i, int j, int m, int n) {
	if(board[i][j] != 0 && board[m][n] != 0) {
		if(board[i][j] == board[m][n]) {
			if(board[i][j] == 1 && (boardPlayer1[i][j] != boardPlayer1[m][n])) {
				updateB(i,j,m,n);
			} 
			if(board[i][j] == -1 && (boardPlayer2[i][j] != boardPlayer2[m][n])) {
				updateW(i,j,m,n);
			}
		}
	}
}

void checkBoard(int i, int j) {
	belong = false;
	if(i-1 >= 0) {
		compare(i,j,i-1,j);
		if(j-1 >= 0)
			compare(i,j,i-1,j-1);
	}
	if (j-1 >= 0)
		compare(i,j,i,j-1);
	if(j+1 < size)
		compare(i,j,i,j+1);
	if (i+1 < size){
		compare(i,j,i+1,j);
		if(j+1 < size)
			compare(i,j,i+1,j+1);
	}
	if (!belong) {
		if(board[i][j] == 1) {
			for(int k = 0; k < size*size/2; k++) {
				if(groupsPlayer1[k] == 0) {
					groupsPlayer1[k] = k+1;
					boardPlayer1[i][j] = k+1;
					break;
				} 					 			
			}
		} 
		if(board[i][j] == -1) {
			for(int k = 0; k < size*size/2; k++) {
				if(groupsPlayer2[k] == 0) {
					groupsPlayer2[k] = k+1;
					boardPlayer2[i][j] = k+1;
					break;
				} 					 			
			}
		} 
	}
}

void move (int player) {
	int i = 0,j = 0;
	if (player == 1)
		cout << "Player 1 plays. ";
	else
		cout << "Player 2 plays.";
	cout << "Choose cell: ";
	while (i < 1 || i > size || j < 1 || j > size)	{
		cin >> i;
		cin >> j;
		if (i < 1 || i > size || j < 1 || j > size)
			cout << "This is not a valid coordinate. Please, choose a cell: ";
	}
	if (board[i-1][j-1] == 0)
		board[i-1][j-1] = player;
	else {
		cout << "This cell isn't free. Please choose an empty cell." << endl;
		move (player);
	}
	checkBoard(i-1,j-1);
}

int main () {
	system ("clear");
	printLogo();
	generateBoard();
	int player = 1;
	while (!isThereAWinner()) {
     	system ("clear");
		printLogo();
		printBoard();
		printBoardPlayer1();
		move(player);
		player*=-1;
	}
	return 0;
}
