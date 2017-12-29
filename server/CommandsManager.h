#ifndef EX5_COMMANDSMANAGER_H
#define EX5_COMMANDSMANAGER_H


#include <map>
#include "Command.h"
#include "GameSettings.h"

class CommandsManager {
public:
    CommandsManager(vector<gameSettings>* gameSet);

    ~CommandsManager();

    void executeCommand(int clientSocket, string command, vector<string> args);

private:
    map<string, Command *> commandsMap;
    vector<gameSettings>* gameSet;
};
#endif //EX5_COMMANDSMANAGER_H
