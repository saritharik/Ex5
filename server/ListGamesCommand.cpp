#include <unistd.h>
#include <iostream>
#include "ListGamesCommand.h"

ListGamesCommand::ListGamesCommand(vector<gameSettings>* gameSet): gameSet(gameSet) {}

void ListGamesCommand::execute(int clientSocket, vector<string> args) {
    cout << "list";

    int numGames = gameSet->size();
    int n = write(clientSocket, &numGames, sizeof(numGames));
    char name[20] = "";
    string na;
    cout << name;

    //vector<string> toUser;
    vector<gameSettings>::iterator it;

    for (it = gameSet->begin(); it != gameSet->end(); it++) {
        //toUser.push_back(it.base()->name);
        na = it.base()->name;
        for (int i = 0; i < na.size() ; ++i) {
            name[i] = na[i];
        }
        cout << "name: " << name << endl;
        n = write(clientSocket, &name, sizeof(name));
    }
    cout << "name: " << name << endl;
    //int n = write(clientSocket, &toUser, sizeof(toUser));
    if (n == -1) {
        cout << "Error";
        //printer.errorWrite();
        return;
    }
}
