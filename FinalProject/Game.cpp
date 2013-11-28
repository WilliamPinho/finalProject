/* 
 * File:   Game.cpp
 * Author: william
 * 
 * Created on 26 November 2013, 15:34
 */

#include "Game.h"
#include "Board.h"
using namespace std;

Game::Game() {
    this->player1 = Player(1);
    this->player2 = Player(2);
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

Game::chooseBoardSize() {
    int size;
    std::cout << "Enter board size: ";
    std::cin >> size;
	if (size < 3) {
	    std::cout << "\nThis is an invalid size. Please choose a size strictly greater than 2." << std::endl;
	    this->chooseBoardSize();
	}
}

Game::printLogo() {
    cout << "------------------------------------------------------------------------" << endl;
    cout << "-                               Hex Game                               -" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    endl(cout);
}

Game::isThereAWinner(Game instance) {
    for(int i = 0; i < this->board.getSize(); i++)
	for(int j = 0; j < this->board.getSize(); j++) {
	    if((this->board.getBoardPlayer(this->player1, 0, i) == this->board.getBoardPlayer(this->player1, this->board.getSize()-1, j)) && (this->board.getBoardPlayer(this->player1, 0, i)*this->board.getBoardPlayer(this->player1, this->board.getSize()-1, j) != 0)) {
	    cout << "Player 1 wins!" << endl;
	    return true;			
	    }
            if((this->board.getBoardPlayer(this->player2, i, 0) == this->board.getBoardPlayer(this->player2, j, this->board.getSize()-1)) && (this->board.getBoardPlayer(this->player2, i, 0)*this->board.getBoardPlayer(this->player2, j, this->board.getSize()-1) != 0)) {
                cout << "Player 2 wins!" << endl;
		return true;			
	    }		
	}
}

Game::printBoard() {
    int size = this->board.getSize()
    cout << endl << endl << endl;
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            string s1(2 * (size - 2), ' ');
            cout << endl << "       " << s1;
            for (int k = 0; k < size; k++) {
                cout << setw(2) << k + 1 << "   ";
            }
            cout << endl << endl << endl;
        }
        cout << setw(3) << i + 1 << "   ";
        if (i < size - 1) {
            cout << "  ";
            string s2(2 * (size - i - 2), ' ');
            cout << s2;
        }
        for (int j = 0; j < size; j++)
            cout << this->board.getBoardPlayer(1,i,j) << "    ";
        cout << endl << endl;
    }
    cout << endl;

}