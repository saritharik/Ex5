#include <unistd.h>
#include <iostream>
#include <cstring>
#include "ClientHandler.h"
#define COMMAND_LEN 250

ClientHandler::ClientHandler(): manager(CommandsManager(&gameSet)) {}

void ClientHandler::handleClient(int socket, string command) {
    vector<string> arguments;
    char args[COMMAND_LEN];
    char com[COMMAND_LEN];
    for (int i = 0; i < command.size(); i++) {
        com[i] = command[i];
    }

    if (strcmp(com, "list_games") != 0) {
        int n = read(socket, &args, sizeof(args));
        if (n == -1) {
            cout << "Error reading args" << endl;
            return;
        }
        arguments.push_back(args);
    }
    manager.executeCommand(socket, command, arguments);
}