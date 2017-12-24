#ifndef EX5_USERPRINTERCONSOLE_H
#define EX5_USERPRINTERCONSOLE_H

#include "UserInterface.h"

class UserPrinterConsole: public UserInterface {
public:
    /**
     * Constructor.
     */
    UserPrinterConsole();
    /**
     * Print the start menu.
     */
    virtual void chooseRival();
    /**
     * Print the current board.
     */
    virtual void startMove();
    /**
     * Print message to current player.
     * @param disk the disk of current player.
     */
    virtual void currentPlayerMsg(char disk);
    /**
     * Print to player the possible moves.
     * @param points vector of possible moves.
     */
    virtual void optionsToMove(vector<Point> points);
    /**
     * Print to player if him choose impossible move.
     * @param points  vector of possible moves.
     */
    virtual void uncorrectMoves(vector<Point> points);
    /**
     * Print the ended result.
     * @param disk the disk of the winner.
     */
    virtual void endOfGame(char disk);
    /**
     * If its play against remote player.
     */
    virtual void remoteHelpPrinter();
    /**
     * Print to remote player what the other player choose.
     * @param disk - the disk of player.
     * @param point - the choosen point.
     */
    virtual void remotePlayerMsg(char disk, Point point);
};
#endif //EX5_USERPRINTERCONSOLE_H
