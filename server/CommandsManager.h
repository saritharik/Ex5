#ifndef EX5_COMMANDSMANAGER_H
#define EX5_COMMANDSMANAGER_H


#include <map>
#include "Command.h"
#include "SocketsNums.h"

class CommandsManager {
public:
    CommandsManager(map<string, gameSockets> *games);

    ~CommandsManager();

    void executeCommand(int clientSocket, string command, vector<string> args);

private:
    map<string, Command *> commandsMap;
    map<string, gameSockets> *games;
};
#endif //EX5_COMMANDSMANAGER_H
