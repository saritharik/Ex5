//
// Created by sarit on 25/12/17.
//

#include <unistd.h>
#include <cstring>
#include "StartCommand.h"
using namespace std;

StartCommand::StartCommand(vector<gameSettings>* gameSet): gameSet(gameSet) {}

void StartCommand::execute(int clientSocket, vector<string> args) {
    bool gameIn = true;
    string key = args[0];
    vector<gameSettings>::iterator it;
    for (it = gameSet->begin(); it != gameSet->end(); it++) {
        if (strcmp(it.base()->name.c_str(), key.c_str()) == 0) {
            int answer = -1;
            int n = write(clientSocket, &answer, sizeof(answer));
            gameIn = false;
            break;
        }
    }
    if (gameIn) {
        gameSettings settings;
        settings.name = key;
        settings.socketX = clientSocket;
        gameSet->push_back(settings);
        int answer = 0;
        int n = write(clientSocket, &answer, sizeof(answer));
    }

}