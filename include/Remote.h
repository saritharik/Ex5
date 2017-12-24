#ifndef EX5_REMOTE_H
#define EX5_REMOTE_H

#include "Player.h"
#include "Client.h"
#include "UserInterface.h"

class Remote: public Player {
public:
    /**
     * constructor
     * @param client - pointer to client, for connect to the server
     * @param disk - the disk of this player
     */
    Remote(Client* client, char disk, UserInterface* printer);
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
     * Set points to player.
     * @param newPoints thr points to set.
     */
    virtual void setPoint(int points);
    /**
     * Returns the points.
     * @return the points.
     */
    virtual int getPoint();
private:
    Client* client;
    char disk;
    int points;
    UserInterface* printer;
};

#endif //EX5_REMOTE_H
