#include <unistd.h>
#include <cstring>
#include <iostream>
#include "JoinCommand.h"
#include "ServerPrinter.h"

JoinCommand::JoinCommand(vector<gameSettings>* gameSet): gameSet(gameSet) {}

void JoinCommand::execute(int clientSocket, vector<string> args) {
    string nameOfGame = args[0];
    bool gameIn = false;
    int socketX, socketO;
    vector<gameSettings>::iterator iter;
    for(iter = gameSet->begin(); iter != gameSet->end(); iter++) {
        if(strcmp(iter.base()->name.c_str(), nameOfGame.c_str()) == 0) {
            if (iter.base()->socketO == 0) {
                gameIn = true;
                iter.base()->socketO = clientSocket;
                int answer1 = 1;
                int answer2 = 2;
                socketX = iter.base()->socketX;
                socketO = iter.base()->socketO;
                int n = write(socketX, &answer1, sizeof(answer1));
                n = write(socketO, &answer2, sizeof(answer2));
                this->gameSet->erase(iter);
                break;
            }
        }
    }
    if (!gameIn) {
        int answer = -1;
        int n = write(clientSocket, &answer, sizeof(answer));
    } else {
        play(socketX, socketO);
        //close(socketX);
        //close(socketO);
        //for (iter = gameSet->begin(); iter != gameSet->end(); iter++) {
         //   if (strcmp(iter.base()->name.c_str(), nameOfGame.c_str()) == 0) {
          //      this->gameSet->erase(iter);
           // }
        //}
        close(socketX);
        close(socketO);
    }
}

void JoinCommand::play(int clientSocketX, int clientSocketO) {
    int xPoint1 = 0, yPoint1 = 0, xPoint2 = 0, yPoint2 = 0;
    ServerPrinter printer;
    while (true) {
        int n = read(clientSocketX, &xPoint1, sizeof(xPoint1));
        if (n == -1) {
            printer.errorRead('x');
            return;
        }
        if (n == 0) {
            printer.disconnect();
            return;
        }

        n = read(clientSocketX, &yPoint1, sizeof(yPoint1));
        if (n == -1) {
            printer.errorRead('y');
            return;
        }
        if (xPoint1 == -1 && yPoint1 == -1) {
            return;
        }

        // Write the result back to the O client
        n = write(clientSocketO, &xPoint1, sizeof(xPoint1));
        if (n == -1) {
            printer.errorWrite();
            return;
        }
        n = write(clientSocketO, &yPoint1, sizeof(yPoint1));

        //move to the O player
        n = read(clientSocketO, &xPoint2, sizeof(xPoint2));
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
        if (xPoint2 == -1 && yPoint2 == -1) {
            return;
        }

        // Write the result back to the X client
        n = write(clientSocketX, &xPoint2, sizeof(xPoint2));
        if (n == -1) {
            printer.errorWrite();
            return;
        }
        n = write(clientSocketX, &yPoint2, sizeof(yPoint2));
    }
}
