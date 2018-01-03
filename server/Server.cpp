#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;
#define MAX_CONNECTED_CLIENTS 10
#define COMMAND_LEN 250

Server::Server(int port): port(port), serverSocket(0) {
    cout << "Server" << endl;
}
void Server::start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }

    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY; //IP
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddressX;
    socklen_t clientAddressLenX;

    while (true) {
        printer.waitToConnection();
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct
                sockaddr *)&clientAddressX, &clientAddressLenX);
        if (clientSocket == -1)
            throw "Error on accept";
        printer.connect();
        pthread_t pthread;
        ThreadArgs* tArgs = new ThreadArgs(&handler, clientSocket);

        pthread_create(&pthread, NULL, handleThread, tArgs);
        threads.push_back(pthread);
    }
}

void* Server::handleThread(void *tArgs) {
    ServerPrinter printer;
    ThreadArgs* args = (ThreadArgs*) tArgs;
    char command[COMMAND_LEN] = "";
    int n = read(args->getSocket(), &command, sizeof(command));
    if (n == -1) {
        printer.errorCommand();
        return 0;
    }
    args->getHandler()->handleClient(args->getSocket(), command);
}

void* Server::startThread(void *server) {
    ServerPrinter printer;
    Server* ser = (Server*)server;
    try {
        ser->start();
    } catch (const char* e) {
       printer.errorBinding();
    }
}

void Server::stop() {
    handler.closeSocket();
    int size = threads.size();
    for (int i = 0; i < size; i++) {
        pthread_cancel(threads[i]);
    }
    close(serverSocket);
}