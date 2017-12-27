//
// Created by tamar on 07/12/17.
//

#include "../include/Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <vector>

using namespace std;

Client::Client(const char *serverIP, int serverPort):
        serverIP(serverIP),
        serverPort(serverPort),
        clientSocket(0) {
    commandMap["start"] = 0;
    commandMap["list_games"] = 1;
    commandMap["join"] = 2;
    commandMap["play"] = 3;
    commandMap["close"] = 4;
    this->disk = ' ';
}

char Client::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }

    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof
            address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char*)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char*)&serverAddress.sin_addr.s_addr, (char
    *)server->h_addr, server->h_length);
    // htons converts values between host and network byte
//    orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr
    *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;

    cout << "Menu:" << endl <<
         "Please choose option:" << endl <<
         "start <name>" << endl <<
         "list_games" << endl <<
         "join <name>" << endl <<
         "play <x> <y>" << endl <<
         "close <name>" << endl;


    //צריך להעביר לפונקציית start
    /*int firstPlayer;

    //int
    n = read(clientSocket, &firstPlayer, sizeof(firstPlayer));
    if (n == -1) {
        throw "Error reading from socket";
    }
    if (firstPlayer == 1) {
        cout << "Waiting for other player to join..." << endl;
    } else if (firstPlayer == 2) {

    }
    int result;
    n = read(clientSocket, &result, sizeof(result));
    if (n == -1) {
        throw "Error reading the player type from socket";
    }
    //return the type of the player
    if (result == 1) {
        return 'X';
    } else if (result == 2) {
        return 'O';
    }*/
}

char Client::getDisk() {
    return this->disk;
}

Point Client::getMessage() {
    int answer, n, d;
    vector<string> listGames;
    vector<string>::iterator it;
    // Read the message from the server
    switch (command) {
        case start:
            n = read(clientSocket, &answer, sizeof(answer));
            if (answer == -1) {
                cout << "There is a game with this name." << endl;
            } else {
                //this->disk = 'X';
                cout << "Waiting for other player to join..." << endl;
                int d;
                //wait to other player
                n = read(clientSocket, &d, sizeof(d));
                if (d == 1) {
                    this->disk = 'X';
                } else if (d == 2) {
                    this->disk = 'O';
                }
            }
            break;

        case list_games:
            n = read(clientSocket, &listGames, sizeof(listGames));
            if (n == -1) {
                cout << "Error" << endl;
            }
            if (listGames.empty()) {
                cout << "There is no games right now" << endl;
                break;
            }
            for (it = listGames.begin(); it!= listGames.end(); it++) {
                cout << it.base() << endl;
            }
            break;

        case join:
            n = read(clientSocket, &d, sizeof(d));
            if (d == -1) {
                cout << "There is no a game with this name." << endl;
            } else if (d == 1) {
                this->disk = 'X';
            } else if (d == 2) {
                this->disk = 'O';
            }
            break;

        case play:
            char x;
            char y;
            n = read(clientSocket, &x, sizeof(x));
            n = read(clientSocket, &y, sizeof(y));
            return Point(x, y);

        case closeGame:
            break;
    }
    return Point(0,0);

}

void Client::sendMessage(Point newPoint) {
    //string com;
    //cin >> com;
    char com[250];  ////magc numbers!!
    //char temp;
    cin >> com;

    cout << com;
    int n = write(clientSocket, &com, sizeof(com));
    if (n == -1) {
        throw "Error writing to server";
    }

    switch (commandMap[com]) {
        case start:
            this->command = start;
            char arg[250];
            cin >> arg;
            n = write(clientSocket, &arg, sizeof(arg));
            break;

        case list_games:
            this->command = list_games;
            // no arguments
            break;

        case join:
            this->command = join;
            cin >> arg;
            n = write(clientSocket, &arg, sizeof(arg));
            break;

        case play:
            this->command = play;
            char arg1[250];
            cin >> arg;
            cin >> arg1;
            n = write(clientSocket, &arg, sizeof(arg));
            n = write(clientSocket, &arg1, sizeof(arg1));
            break;

        case closeGame:
            this->command = closeGame;
            cin >> arg;
            n = write(clientSocket, &arg, sizeof(arg));
            break;

        default:
            cout << "It is not available choice" << endl;
            break;
    }
}