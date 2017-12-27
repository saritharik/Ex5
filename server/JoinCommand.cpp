//
// Created by sarit on 25/12/17.
//

#include <unistd.h>
#include "JoinCommand.h"
JoinCommand::JoinCommand(map<string, gameSockets> *games): games(games) {}

void JoinCommand::execute(int clientSocket, vector<string> args) {
    string key = args[0];
    if (games->find(key) == games->end()) {
        int answer = -1;
        int n = write(clientSocket, &answer, sizeof(answer));
    } else {
        games->find(key)->second.socketO = clientSocket;
        int answer1 = 1;
        int answer2 = 2;
        int n = write(games->find(key)->second.socketX, &answer1, sizeof(answer1));
        n = write(games->find(key)->second.socketO, &answer2, sizeof(answer2));
    }
}