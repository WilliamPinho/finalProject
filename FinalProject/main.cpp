/* 
 * File:   main.cpp
 * Author: william
 *
 * Created on 24 November 2013, 15:14
 */

 #include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
    Game instance;
    system ("clear");
    instance.printLogo();
    instance.generateBoard();
    while (!instance.isThereAWinner()) {
    	system ("clear");
	printLogo();
	printBoard();
	printBoardPlayer1();
	move(player);
	player*=-1;
    }
    return 0;
}
