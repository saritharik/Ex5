
#ifndef EX5_USERINTERFACE_H
#define EX5_USERINTERFACE_H

#include "Point.h"
#include <vector>
using namespace std;

class UserInterface {
public:
    /**
     * Print the start menu.
     */
    virtual void chooseRival() = 0;
    /**
     * Print the current board.
     */
    virtual void startMove() = 0;
    /**
     * Print message to current player.
     * @param disk the disk of current player.
     */
    virtual void currentPlayerMsg(char disk) = 0;
    /**
     * Print to player the possible moves.
     * @param points vector of possible moves.
     */
    virtual void optionsToMove(vector<Point> points) = 0;
    /**
     * Print to player if him choose impossible move.
     * @param points  vector of possible moves.
     */
    virtual void uncorrectMoves(vector<Point> points) = 0;
    /**
     * Print the ended result.
     * @param disk the disk of the winner.
     */
    virtual void endOfGame(char disk) = 0;
    /**
     * If its play against remote player.
     */
    virtual void remoteHelpPrinter() = 0;
    /**
     * Print to remote player what the other player choose.
     * @param disk - the disk of player.
     * @param point - the choosen point.
     */
    virtual void remotePlayerMsg(char disk, Point point) = 0;
};

#endif //EX5_USERINTERFACE_H
