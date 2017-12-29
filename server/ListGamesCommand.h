//
// Created by sarit on 25/12/17.
//

#ifndef EX5_LISTGAMESCOMMAND_H
#define EX5_LISTGAMESCOMMAND_H


#include "Command.h"
#include "ClientHandler.h"

class ListGamesCommand: public Command {
public:
    ListGamesCommand(vector<gameSettings>* gameSet);
    virtual void execute(int clientSocket, vector<string> args);

private:
    vector<gameSettings>* gameSet;
};


#endif //EX5_LISTGAMESCOMMAND_H
