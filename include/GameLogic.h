#ifndef EX5_GAMELOGIC_H
#define EX5_GAMELOGIC_H

#include "BoardConsole.h"
#include <vector>
#include "Point.h"
#include "Human.h"

using namespace std;

class GameLogic {
public:
    /**
     * Constructor.
     * @param p1 first player.
     * @param p2 second player.
     */
    GameLogic(Board* b);
    /**
     * Replace one disk in other.
     * @param i the row.
     * @param j the col.
     */
    void replaceDisk(int i, int j);
    /**
     * Checking which points need to replace.
     * @param i the row.
     * @param j the col.
     * @param a the disk.
     * @return vector of all points.
     */
    vector<Point> checking(int i, int j, char a);
    /**
     * Make one move in the game.
     * @param i the row.
     * @param j the col.
     * @param a the disk.
     */
    void oneMove(int i, int j, char a);
    /**
     * Find the possible locations to put disks.
     * @param a the disk.
     * @return list of points.
     */
    vector<Point> findPoints(char a);
    /**
     * Check if the player choose right location.
     * @param p the selected point.
     * @param a the disk.
     * @return true or false.
     */
    bool possibleMoves(Point p, char a);
    /**
     * Returns points of each player.
     * @param player - to return him points.
     * @return points.
     */
    int getPointsByPlayer(char player);
    /**
     * Set points to player.
     * @param player - to which player set points.
     * @param points - the number of points.
     */
    void setPlayerPoints(char player, int points);

private:
    Board* b;
    vector<Point> v;
    int xPoints;
    int oPoints;

};


#endif //EX5_GAMELOGIC_H
