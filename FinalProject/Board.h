/* 
 * File:   Board.h
 * Author: william
 *
 * Created on 24 November 2013, 15:18
 */

#ifndef BOARD_H
#define	BOARD_H

class Board {
public:
    Board();
    Board(const Board& orig);
    virtual ~Board();
    boardSizeSet(int size);
private:
    int size;
    int ** board;
    int ** boardPlayer1;
    int * groupsPlayer1;
    int ** boardPlayer2;
    int * groupsPlayer2;
};

#endif	/* BOARD_H */

