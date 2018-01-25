#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/GameLogic.h"
#include "../include/AI.h"
#include "../include/Game.h"
#include "../include/UserPrinterConsole.h"
#include "../include/Client.h"
#include "../include/Remote.h"
#include "../include/VirtualRemote.h"
using namespace std;

int main() {
    int const defaultSizeBoard = 8;
    BoardConsole bC(defaultSizeBoard, defaultSizeBoard);
    GameLogic gameLogic(&bC);
    Human p1('X');
    UserPrinterConsole printer;
    printer.chooseRival();
    int choice;
    cin >> choice;
    if (choice == 1) {
        Human p2('O');
        Game game(&p1, &p2, &bC, &gameLogic, &printer, false);
        game.playGame();
    } else if (choice == 2) {
        AI p2(&gameLogic, &bC);
        Game game(&p1, &p2, &bC, &gameLogic, &printer, false);
        game.playGame();
    } else if (choice == 3) {
        int port;
        char IP[10];
        char temp;
        ifstream reader;
        reader.open("../exe/clientSettings.txt");
        reader >> temp;
        while (temp != '=') {
            reader >> temp;
        }
        reader >> port;
        reader >> temp;
        while (temp != '=') {
            reader >> temp;
        }
        reader >> IP;
        IP[9] = '\n';
        reader.close();
        Client client(IP, port);
        //Client client("127.0.0.1", 8000);
        bool connect = true;
        string command;
        while (connect) {
            char disk = ' ';
            client.setDisk(disk);
            while (disk == ' ') {
                try {
                    client.connectToServer();
                } catch (const char* e){
                    connect = false;
                    break;
                }
                cout << "Menu:" << endl <<
                     "Please choose option:" << endl <<
                     "start <name>" << endl <<
                     "list_games" << endl <<
                     "join <name>" << endl;
                command = client.sendCommand();
                client.sendMessage(Point(0, 0));
                client.getMessage();
                disk = client.getDisk();
                if (strcmp(command.c_str(), "start") == 0) {
                    break;
                }
            }
            if (connect) {
                BoardConsole boardC(defaultSizeBoard, defaultSizeBoard);
                GameLogic gameLogic(&boardC);
                Remote player1(&client, disk, &printer);
                char rivalDisk = ' ';
                if (disk == 'X') {
                    rivalDisk = 'O';
                    VirtualRemote player2(&client, rivalDisk, &printer);
                    Game game(&player1, &player2, &boardC, &gameLogic, &printer, true);
                    game.playGame();
                } else if (disk == 'O') {
                    rivalDisk = 'X';
                    VirtualRemote player2(&client, rivalDisk, &printer);
                    Game game(&player2, &player1, &boardC, &gameLogic, &printer, true);
                    game.playGame();
                }
            }
        }
    }
    return 0;
}