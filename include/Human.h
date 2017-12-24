#ifndef EX5_HUMAN_H
#define EX5_HUMAN_H


#include "Player.h"
#include "Point.h"

class Human: public Player {
public:
    /**
     * Constructor.
     * @param p the disk.
     */
    Human(char p);
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
     * Set disk.
     * @param d the char of the disk.
     */
    void setDisk(char d);
    /**
     * Set points to player.
     * @param newPoints thr points to set.
     */
    void setPoint(int newPoints);
    /**
     * Returns the points.
     * @return the points.
     */
    int getPoint();


private:
    char disk;
    int points;
};


#endif //EX5_HUMAN_H
