#include "../include/Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#define NAMES_OF_GAMES 50
#define COMMAND_LEN 250


using namespace std;

Client::Client(const char *serverIP, int serverPort):
        serverIP(serverIP),
        serverPort(serverPort),
        clientSocket(0) {
    commandMap["start"] = 0;
    commandMap["list_games"] = 1;
    commandMap["join"] = 2;
    commandMap["play"] = 3;
    //commandMap["close"] = 4;
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
    //orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr
    *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
}

char Client::getDisk() {
    return this->disk;
}

void Client::setDisk(char d) {
    this->disk = d;
}

Point Client::getMessage() {
    int answer, n, d, x, y, numOfGames;
    char name[NAMES_OF_GAMES] = "";
    Point point(0,0);
    vector<string> listGames;
    vector<string>::iterator it;
    // Read the message from the server
    switch (command) {
        case start:
            n = read(clientSocket, &answer, sizeof(answer));
            if (answer == -1) {
                cout << "There is a game with this name." << endl;
            } else {
                cout << "Waiting for other player to join..." << endl;
                //wait to other player
                n = read(clientSocket, &d, sizeof(d));
                if (d == 1) {
                    this->disk = 'X';
                } else if (d == 2) {
                    this->disk = 'O';
                }
                command = play;
            }
            break;

        case list_games:
            n = read(clientSocket, &numOfGames, sizeof(numOfGames));
            for (int i = 0; i < numOfGames ; ++i) {
                n = read(clientSocket, &name, sizeof(name));
                cout << name << endl;
            }
            if (n == -1) {
                cout << "Error" << endl;
            }
            if (numOfGames == 0) {
                cout << "There is no games right now" << endl;
                break;
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
            command = play;
            break;

        case play:
            n = read(clientSocket, &x, sizeof(x));
            n = read(clientSocket, &y, sizeof(y));
            if (8 < x || x < 0) {
                point.setX(-1);
                point.setY(-1);
            } else {
                point.setX(x);
                point.setY(y);
            }
            return point;
    }
    return point;

}

void Client::sendMessage(Point newPoint) {
    int x = newPoint.getX();
    int y = newPoint.getY();

    int n;
    switch (command) {
        case start:
            char arg[250];
            cin >> arg;
            n = write(clientSocket, &arg, sizeof(arg));
            break;

        case list_games:
            break;

        case join:
            cin >> arg;
            n = write(clientSocket, &arg, sizeof(arg));
            break;

        case play:
            n = write(clientSocket, &x, sizeof(x));
            if (n == -1) {
                throw "Server disconnected";
            }
            n = write(clientSocket, &y, sizeof(y));
            break;

        default:
            cout << "It is not available choice" << endl;
            break;
    }
}

string Client::sendCommand() {
    char com[COMMAND_LEN] = "";
    cin >> com;
    int n = write(clientSocket, &com, sizeof(com));
    if (n == -1) {
        throw "Error writing to server";
    }

    switch (commandMap[com]) {
        case start:
            this->command = start;
            break;

        case list_games:
            this->command = list_games;
            break;

        case join:
            this->command = join;
            break;

        case play:
            this->command = play;
            break;


        default:
            cout << "It is not available choice" << endl;
            break;
    }
    return com;
}