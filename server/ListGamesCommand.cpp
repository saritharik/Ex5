#include <unistd.h>
#include <iostream>
#include "ListGamesCommand.h"
#define NAMES_OF_GAMES 20

ListGamesCommand::ListGamesCommand(vector<gameSettings>* gameSet): gameSet(gameSet) {}

void ListGamesCommand::execute(int clientSocket, vector<string> args) {
    int numGames = gameSet->size();
    int n = write(clientSocket, &numGames, sizeof(numGames));
    char name[NAMES_OF_GAMES] = "";
    string na;
    vector<gameSettings>::iterator it;

    for (it = gameSet->begin(); it != gameSet->end(); it++) {
        na = it.base()->name;
        for (int i = 0; i < na.size() ; ++i) {
            name[i] = na[i];
        }
        n = write(clientSocket, &name, sizeof(name));
    }
    if (n == -1) {
        cout << "Error";
        //printer.errorWrite();
        return;
    }
    close(clientSocket);
}
