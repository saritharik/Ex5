#include <unistd.h>
#include <iostream>
#include "ClientHandler.h"

ClientHandler::ClientHandler(): manager(CommandsManager(&games)) {}

void ClientHandler::handleClient(int socket, string command) {
    vector<string> arguments;
    char args[250];
    if (command != "list_games") {
        int n = read(socket, &args, sizeof(args));
        if (n == -1) {
            cout << "Error reading args" << endl;
            return;
        }
        arguments.push_back(args);

        if (command.compare("play") == 0) {
            n = read(socket, &args, sizeof(args));
            if (n == -1) {
                cout << "Error reading args" << endl;
                return;
            }
            arguments.push_back(args);
        }
    }

    manager.executeCommand(socket, command, arguments);
}