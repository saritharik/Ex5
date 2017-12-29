//
// Created by sarit on 25/12/17.
//


#include <unistd.h>
#include <iostream>
#include "PlayCommand.h"
#include "../include/Point.h"
#include "ServerPrinter.h"

PlayCommand::PlayCommand(map<string, gameSettings>* games): games(games) {}

void PlayCommand::execute(int clientSocket, vector<string> args) {
    cout << "play" << endl;

    ServerPrinter printer;
    int x, y;
    int n = read(clientSocket, &x, sizeof(x));
    n = read(clientSocket, &y, sizeof(y));
    Point move(x, y);

    int clientSocket2;
    map<string, gameSettings>::iterator mapIt;
    for (mapIt = games->begin(); mapIt != games->end(); mapIt++) {
        if (mapIt->second.socketX == clientSocket) {
            clientSocket2 = mapIt->second.socketO;
        } else if (mapIt->second.socketO == clientSocket) {
            clientSocket2 = mapIt->second.socketX;
        }
    }
    // Write the result back to the O client
    n = write(clientSocket2, &move, sizeof(move));
    if (n == -1) {
        printer.errorWrite();
        return;
    }

    //move to the O player
 /*   n = read(clientSocketO, &xPoint2, sizeof(xPoint2));
    if (n == -1) {
        printer.errorRead('x');
        return;
    }
    if (n == 0) {
        printer.disconnect();
        return;
    }

    n = read(clientSocketO, &yPoint2, sizeof(yPoint2));
    if (n == -1) {
        printer.errorRead('y');
        return;
    }
    Point moveO(xPoint2, yPoint2);
    if (xPoint2 == -1 && yPoint2 == -1) {
        //close(clientSocketO);
        return;
    }

    // Write the result back to the X client
    n = write(clientSocketX, &moveO, sizeof(moveO));
    if (n == -1) {
        printer.errorWrite();
        return;
    }*/
}