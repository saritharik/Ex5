//
// Created by sarit on 25/12/17.
//

#ifndef EX5_CLIENTHANDLER_H
#define EX5_CLIENTHANDLER_H

#include "CommandsManager.h"
#include "SocketsNums.h"


class ClientHandler {
public:
    ClientHandler();
    void handleClient(int socket, string command);
private:
    CommandsManager manager;
    //vector<string> listGames;
    map<string, gameSockets> games;
};


#endif //EX5_CLIENTHANDLER_H