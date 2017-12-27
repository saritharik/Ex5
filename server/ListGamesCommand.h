//
// Created by sarit on 25/12/17.
//

#ifndef EX5_LISTGAMESCOMMAND_H
#define EX5_LISTGAMESCOMMAND_H


#include "Command.h"
#include "ClientHandler.h"

class ListGamesCommand: public Command {
public:
    ListGamesCommand(map<string, gameSockets>* games);
    virtual void execute(int clientSocket, vector<string> args);

private:
    map<string, gameSockets>* games;
};


#endif //EX5_LISTGAMESCOMMAND_H
