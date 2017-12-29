#include <unistd.h>
#include <iostream>
#include <cstring>
#include "ClientHandler.h"

ClientHandler::ClientHandler(): manager(CommandsManager(&gameSet)) {}

void ClientHandler::handleClient(int socket, string command) {
    vector<string> arguments;
    char args[250];
    char com[250];
    for (int i = 0; i < command.size(); i++) {
        com[i] = command[i];
    }
    //do {
        if (strcmp(com, "list_games") != 0) {
            int n = read(socket, &args, sizeof(args));
            if (n == -1) {
                cout << "Error reading args" << endl;
                return;
            }
            arguments.push_back(args);
        }
        manager.executeCommand(socket, command, arguments);
      //  int n = read(socket, &com, sizeof(com));
    //} while (strcmp (com, "close") != 0);
}