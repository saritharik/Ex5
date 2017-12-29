//
// Created by sarit on 25/12/17.
//

#ifndef EX5_JOINCOMMAND_H
#define EX5_JOINCOMMAND_H


#include <map>
#include "Command.h"
#include "GameSettings.h"

class JoinCommand: public Command {
public:
    JoinCommand(vector<gameSettings>* gameSet);
    virtual void execute(int clientSocket, vector<string> args);
    void play(int socX, int socO);
private:
    vector<gameSettings>* gameSet;
};


#endif //EX5_JOINCOMMAND_H
