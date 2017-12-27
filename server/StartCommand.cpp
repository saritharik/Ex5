//
// Created by sarit on 25/12/17.
//

#include <unistd.h>
#include "StartCommand.h"
using namespace std;

StartCommand::StartCommand(map<string, gameSockets>* games): games(games) {}

void StartCommand::execute(int clientSocket, vector<string> args) {
    string key = args[0];
    if (games->find(key) != games->end()) {
        int answer = -1;
        int n = write(clientSocket, &answer, sizeof(answer));
    } else {
        gameSockets g;
        g.socketX = clientSocket;
        games->insert(pair<string,gameSockets>(key,g));
        int answer = 0;
        int n = write(clientSocket, &answer, sizeof(answer));
    }
}