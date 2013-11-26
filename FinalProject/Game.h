/* 
 * File:   Game.h
 * Author: william
 *
 * Created on 26 November 2013, 15:34
 */

#ifndef GAME_H
#define	GAME_H

class Game {
public:
    Board board;
    Game();
    Game(const Game& orig);
    virtual ~Game();
    chooseBoardSize();
    printLogo();
    isThereAWinner();
    generateBoard();
private:
    Player player1;
    Player player2;

};

#endif	/* GAME_H */

