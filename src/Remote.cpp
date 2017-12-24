//
// Created by tamar on 07/12/17.
//

#include "../include/Remote.h"
#include <iostream>
#include <limits>

using namespace std;

Remote::Remote(Client* client1, char d, UserInterface* printer):
        client(client1), disk(d), printer(printer) {
    points = 0;
}

Point Remote::chooseSquare(vector<Point> vecPoints) {
    bool b = false;
    int x, y;

    if (vecPoints.empty()) {
        client->sendMessage(Point(0, 0));
        return Point(0,0);
    }
    Point end = vecPoints[0];
    if (end.getX() == -1 && end.getY() == -1) {
        client->sendMessage(end);
        return end;
    }
    printer->currentPlayerMsg(disk);
    printer->optionsToMove(vecPoints);


    while (b == false) {
        char a;
        cin >> x >> a >> y;
        while (!x || !y) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> x >> a >> y;
        }
        vector<Point>::iterator iter;
        for (iter = vecPoints.begin(); iter != vecPoints.end(); iter++) {
            if ((iter.base()->getX() == x) &&
                iter.base()->getY() == y) {
                b = true;
                break;
            }
        }
    }
    client->sendMessage(Point(x, y));
    return Point(x, y);
}

char Remote::getDisk() {
    return this->disk;
}

int Remote::getPoint() {
    return points;
}
void Remote::setPoint(int newPoints) {
    this->points += newPoints;
}