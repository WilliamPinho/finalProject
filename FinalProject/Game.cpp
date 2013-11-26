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