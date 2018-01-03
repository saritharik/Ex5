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
        if (n == 0) {
            cout << "Client disconnected" << endl;
            return;
        }
        arguments.push_back(args);
    }
    manager.executeCommand(socket, command, arguments);
}

void ClientHandler::closeSocket() {
    vector<gameSettings>::iterator it;
    for (it = gameSet.begin(); it != gameSet.end(); it++) {
        if (it.base()->socketX != 0) {
            int closeClient = -1;
            int n = write(it.base()->socketX, &closeClient, sizeof(closeClient));
            n = write(it.base()->socketX, &closeClient, sizeof(closeClient));
            close(it.base()->socketX);
        }
        if (it.base()->socketO != 0) {
            int closeClient = -1;
            int n = write(it.base()->socketO, &closeClient, sizeof(closeClient));
            n = write(it.base()->socketO, &closeClient, sizeof(closeClient));
            close(it.base()->socketO);
        }
    }
}