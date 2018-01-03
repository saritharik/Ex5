#ifndef EX5_STARTCOMMAND_H
#define EX5_STARTCOMMAND_H


#include <map>
#include "Command.h"
#include "GameSettings.h"

class StartCommand: public Command {
public:
    /**
     * Constructor.
     * @param gameSet - vector of games.
     */
    StartCommand(vector<gameSettings>* gameSet);
    /**
     * Execute the relevant command.
     * @param clientSocket - num of socket.
     * @param args - arguments.
     */
    virtual void execute(int clientSocket, vector<string> args);

private:
    vector<gameSettings>* gameSet;
};


#endif //EX5_STARTCOMMAND_H
