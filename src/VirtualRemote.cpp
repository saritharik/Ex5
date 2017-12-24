//
// Created by tamar on 07/12/17.
//

#include <iostream>
#include "../include/VirtualRemote.h"
#include "../include/UserInterface.h"

VirtualRemote::VirtualRemote(Client *client1, char d, UserInterface* printer):
        client(client1), disk(d), printer(printer) {
    points = 0;
    //this->disk = client->connectToServer();
}

Point VirtualRemote::chooseSquare(vector<Point> vecPoints) {
    Point point(-7,-7);
    printer->remoteHelpPrinter();
   // cout << "Waiting for other player's move..." << endl;
    point = client->getMessage();
    if (point.getX() == 0 && point.getY() == 0 && vecPoints.empty()) {
        return Point(-1, -1);
    }
    if (vecPoints.empty()) {
        return Point(0,0);
    }

    if (point.getX() != 0 && point.getX() != -1) {
        printer->remotePlayerMsg(disk, point);
    }
    /*if (disk == 'O') {
        cout << "O";
    } else {
        cout << "X ";
    }
    cout << "played (" << point.getX() << "," << point.getY() << ")" << endl;*/
    return point;
}

char VirtualRemote::getDisk() {
    return this->disk;
}

int VirtualRemote::getPoint() {
    return points;
}
void VirtualRemote::setPoint(int newPoints) {
    this->points += newPoints;
}