#ifndef EX5_CLOSECOMMAND_H
#define EX5_CLOSECOMMAND_H

#include "Command.h"
#include "GameSettings.h"

class CloseCommand: public Command {
public:
    /**
     * Constructor.
     * @param gameSet - vector of games.
     */
    CloseCommand(vector<gameSettings>* gameSet);
    /**
     * Execute the relevant command.
     * @param clientSocket - num of socket.
     * @param args - arguments.
     */
    virtual void execute(int clientSocket, vector<string> args);

private:
    vector<gameSettings>* gameSet;

};


#endif //EX5_CLOSECOMMAND_H
