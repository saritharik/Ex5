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
        try {
            client->sendMessage(Point(0, 0));
        } catch (const char* e) {
            cout << "Server disconnect" << endl;
        }
        return Point(0,0);
    }
    Point end = vecPoints[0];
    if (end.getX() == -1 && end.getY() == -1) {
        try {
            client->sendMessage(end);
        } catch (const char* e) {
            cout << "Server disconnect" << endl;
        }

        return end;
    }
    printer->currentPlayerMsg(disk);
    printer->optionsToMove(vecPoints);
    //client->sendCommand();

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
        //printer->uncorrectMoves(vecPoints);
    }
    try {
        client->sendMessage(Point(x, y));
    } catch (const char* e) {
        cout << "Server disconnect" << endl;
    }
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