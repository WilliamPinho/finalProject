/* 
 * File:   Board.cpp
 * Author: william
 * 
 * Created on 24 November 2013, 15:18
 */

#include "Board.h"
#include "Game.h"

Board::Board(Game instance) {
    this->boardSizeSet(instance.chooseBoardSize());
    this->board = (int **) calloc (size, sizeof(int *));
    this->boardPlayer1 = (int **) calloc (size, sizeof(int *));
    this->groupsPlayer1 = (int *) calloc (size*size/2, sizeof(int));
    this->boardPlayer2 = (int **) calloc (size, sizeof(int *));
    groupsPlayer2 = (int *) calloc (size*size/2, sizeof(int));
    for (int i = 0; i < size; i++) {
        this->board[i] = (int *) calloc (size, sizeof(int));
        this->boardPlayer1[i] = (int *) calloc (size, sizeof(int));
        this->boardPlayer2[i] = (int *) calloc (size, sizeof(int));
    }
}

Board::Board(const Board& orig) {
}

Board::~Board() {
}

Board::boardSizeSet(int size) {
    this->size = size;
}

Board::getSize() {
    return this->size;
}

Board::getBoardPlayer(Player player, int row, int column) {
    if(Player.getNum() == 1)    return this->boardPlayer1[row][column];
    else                        return this->boardPlayer2[row][column];
}
