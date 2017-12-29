#include <cstring>
#include <unistd.h>
#include "CloseCommand.h"

CloseCommand::CloseCommand(vector<gameSettings>* gameSet): gameSet(gameSet) {}

void CloseCommand::execute(int clientSocket, vector<string> args) {
    string nameGame = args[0];
    vector<gameSettings>::iterator it;
    for (it = gameSet->begin(); it != gameSet->end(); it++) {
        if (strcmp(it.base()->name.c_str(), nameGame.c_str()) == 0) {
            close(it.base()->socketX);
            close(it.base()->socketO);
            gameSet->erase(it);
        }
    }
}