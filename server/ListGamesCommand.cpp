#include <unistd.h>
#include <iostream>
#include "ListGamesCommand.h"
#include "ServerPrinter.h"

#define NAMES_OF_GAMES 50

ListGamesCommand::ListGamesCommand(vector<gameSettings>* gameSet): gameSet(gameSet) {}

void ListGamesCommand::execute(int clientSocket, vector<string> args) {
    ServerPrinter printer;
    vector<gameSettings>::iterator it;
    int numGames = 0;
    for (it = gameSet->begin(); it != gameSet->end(); it++) {
        if (it.base()->socketO == 0) {
            numGames++;
        }
    }
    int n = write(clientSocket, &numGames, sizeof(numGames));
    char name[NAMES_OF_GAMES] = "";
    string na;
    for (it = gameSet->begin(); it != gameSet->end(); it++) {
        if(it.base()->socketO == 0) {
            na = it.base()->name;
            for (int i = 0; i < na.size(); ++i) {
                name[i] = na[i];
            }
            n = write(clientSocket, &name, sizeof(name));
        }
    }
    if (n == -1) {
        printer.errorWrite();
        return;
    }
    close(clientSocket);
}
