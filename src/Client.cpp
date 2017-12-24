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
using namespace std;

Client::Client(const char *serverIP, int serverPort):
        serverIP(serverIP),
        serverPort(serverPort),
        clientSocket(0) {
    cout << "Client" << endl;
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
    int firstPlayer;
    int n = read(clientSocket, &firstPlayer, sizeof(firstPlayer));
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
    }
}

Point Client::getMessage() {
    // Read the message from the server
    Point message(0,0);
    int n = read(clientSocket, &message, sizeof(message));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    return message;
}

void Client::sendMessage(Point newPoint) {
    int xPoint = newPoint.getX();
    int yPoint = newPoint.getY();
    // Write the exercise arguments to the socket
    int n = write(clientSocket, &xPoint, sizeof(xPoint));
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
    n = write(clientSocket, &yPoint, sizeof(yPoint));
    if (n == -1) {
        throw "Error writing arg2 to socket";
    }
}