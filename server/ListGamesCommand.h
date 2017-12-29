#ifndef EX5_LISTGAMESCOMMAND_H
#define EX5_LISTGAMESCOMMAND_H


#include "Command.h"
#include "ClientHandler.h"

class ListGamesCommand: public Command {
public:
    /**
     * Constructor.
     * @param gameSet - vector of games.
     */
    ListGamesCommand(vector<gameSettings>* gameSet);
    /**
     * Execute the relevant command.
     * @param clientSocket - num of socket.
     * @param args - arguments.
     */
    virtual void execute(int clientSocket, vector<string> args);

private:
    vector<gameSettings>* gameSet;
};


#endif //EX5_LISTGAMESCOMMAND_H
