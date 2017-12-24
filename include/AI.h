#ifndef EX5_AI_H
#define EX5_AI_H


#include "Player.h"
#include "GameLogic.h"

class AI: public Player {
public:
    /**
     * Constructor.
     * @param g game logic.
     * @param b board.
     */
    AI(GameLogic *g, Board *b);
    /**
    * Choose square.
    * @return the location of the square.
    */
    virtual Point chooseSquare(vector<Point> vecPoints);
    /**
     * Return the disk.
     * @return the disk.
     */
    virtual char getDisk();
    /**
     * Returns the max value that the rival get from specific move.
     * @return max value.
     */
    int maxOption();
    /**
     * Set the point of player.
     * @param newPoints - the new points.
     */
    void setPoint(int newPoints);
    /**
     * Returns the points of player.
     * @return points.
     */
    int getPoint();

private:
    Board *board;
    GameLogic *game;
    int points;
};


#endif //EX5_AI_H
