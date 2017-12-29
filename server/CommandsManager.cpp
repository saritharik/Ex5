//
// Created by sarit on 25/12/17.
//

#include "CommandsManager.h"
#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"
#include "PlayCommand.h"
#include "CloseCommand.h"

CommandsManager::CommandsManager(vector<gameSettings>* gameSet): gameSet(gameSet) {
    commandsMap["start"] = new StartCommand(gameSet);
    commandsMap["list_games"] = new ListGamesCommand(gameSet);
    commandsMap["join"] = new JoinCommand(gameSet);
    //commandsMap["play"] = new PlayCommand();
    //commandsMap["close"] = new CloseCommand();
}

void CommandsManager::executeCommand(int clientSocket, string command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(clientSocket, args);
}

CommandsManager::~CommandsManager() {
    map<string, Command *>:: iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        //delete it->second;
    }
}