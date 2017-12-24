#ifndef EX5_PLAYER_H
#define EX5_PLAYER_H


#include "Point.h"
#include <vector>
using namespace std;

class Player {
public:
    /**
     * Choose square.
     * @return the location of the square.
     */
    virtual Point chooseSquare(vector<Point> vecPoints) = 0;
    /**
     * Return the disk.
     * @return the disk.
     */
    virtual char getDisk() = 0;
    /**
     * Set points to player.
     * @param newPoints thr points to set.
     */
    virtual void setPoint(int points) = 0;
    /**
     * Returns the points.
     * @return the points.
     */
    virtual int getPoint() = 0;

};


#endif //EX5_PLAYER_H
