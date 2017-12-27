#include <unistd.h>
#include <iostream>
#include "ListGamesCommand.h"

ListGamesCommand::ListGamesCommand(map<string, gameSockets>* games): games(games) {}

void ListGamesCommand::execute(int clientSocket, vector<string> args) {
    vector<string> toUser;
    map<string, gameSockets>::iterator it;
    for (it = games->begin(); it != games->end(); it++) {
        toUser.push_back(it->first);
    }
    int n = write(clientSocket, &toUser, sizeof(toUser));
    if (n == -1) {
        cout << "Error";
        //printer.errorWrite();
        return;
    }
}

