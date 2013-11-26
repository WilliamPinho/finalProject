/* 
 * File:   Game.cpp
 * Author: william
 * 
 * Created on 26 November 2013, 15:34
 */

#include "Game.h"

Game::Game() {
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

Game::chooseBoardSize() {
    int size;
    cout << "Enter board size: ";
    cin >> size;
	if (size < 3) {
	    cout << "\nThis is an invalid size. Please choose a size strictly greater than 2." << endl;
	    this->chooseBoardSize();
	}
}

