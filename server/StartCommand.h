//
// Created by sarit on 25/12/17.
//

#ifndef EX5_STARTCOMMAND_H
#define EX5_STARTCOMMAND_H


#include <map>
#include "Command.h"
#include "GameSettings.h"

class StartCommand: public Command {
public:
    StartCommand(vector<gameSettings>* gameSet);
    virtual void execute(int clientSocket, vector<string> args);

private:
    vector<gameSettings>* gameSet;
};


#endif //EX5_STARTCOMMAND_H
