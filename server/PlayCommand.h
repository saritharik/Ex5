//
// Created by sarit on 25/12/17.
//

#ifndef EX5_PLAYCOMMAND_H
#define EX5_PLAYCOMMAND_H

#include "Command.h"
#include <map>
#include "GameSettings.h"

class PlayCommand: public Command {
public:
    PlayCommand(map<string, gameSettings>* games);
    virtual void execute(int clientSocket, vector<string> args);

private:
    map<string, gameSettings>* games;
};


#endif //EX5_PLAYCOMMAND_H
