#ifndef EX5_JOINCOMMAND_H
#define EX5_JOINCOMMAND_H


#include <map>
#include "Command.h"
#include "GameSettings.h"

class JoinCommand: public Command {
public:
    /**
     * Constructor.
     * @param gameSet - vector of games.
     */
    JoinCommand(vector<gameSettings>* gameSet);
    /**
     * Execute the relevant command.
     * @param clientSocket - num of socket.
     * @param args - arguments.
     */
    virtual void execute(int clientSocket, vector<string> args);
    /**
     * Run the game.
     * @param socX - socket player X.
     * @param socO - socket player Y.
     */
    void play(int socX, int socO);
private:
    vector<gameSettings>* gameSet;
};


#endif //EX5_JOINCOMMAND_H
