#ifndef EX5_COMMANDSMANAGER_H
#define EX5_COMMANDSMANAGER_H


#include <map>
#include "Command.h"
#include "GameSettings.h"

class CommandsManager {
public:
    /**
     * Constructor.
     * @param gameSet - vector of games settings.
     */
    CommandsManager(vector<gameSettings>* gameSet);
    /**
     * D'tor.
     */
    ~CommandsManager();
    /**
     * Mange the execute of commands.
     * @param clientSocket - num of socket.
     * @param command - the command.
     * @param args - arguments.
     */
    void executeCommand(int clientSocket, string command, vector<string> args);

private:
    map<string, Command *> commandsMap;
    vector<gameSettings>* gameSet;
};
#endif //EX5_COMMANDSMANAGER_H
