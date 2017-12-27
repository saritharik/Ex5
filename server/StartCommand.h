//
// Created by sarit on 25/12/17.
//

#ifndef EX5_STARTCOMMAND_H
#define EX5_STARTCOMMAND_H


#include <map>
#include "Command.h"
#include "SocketsNums.h"

class StartCommand: public Command {
public:
    StartCommand(map<string, gameSockets>* games);
    virtual void execute(int clientSocket, vector<string> args);

private:
    map<string, gameSockets>* games;
};


#endif //EX5_STARTCOMMAND_H
