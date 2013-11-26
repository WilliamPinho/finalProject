/* 
 * File:   Player.h
 * Author: william
 *
 * Created on 26 November 2013, 16:09
 */

#ifndef PLAYER_H
#define	PLAYER_H

class Player {
public:
    Player(int num);
    Player(const Player& orig);
    virtual ~Player();
    getNum();
private:
    int num;
};

#endif	/* PLAYER_H */

