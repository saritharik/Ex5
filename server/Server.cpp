#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace std;
#define MAX_CONNECTED_CLIENTS 2
#define COMMAND_LEN 250
#define THREADS_NUM 5

Server::Server(int port): port(port), serverSocket(0) {
    this->pool = new ThreadPool(THREADS_NUM);
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
        //pthread_t pthread;
        ThreadArgs* tArgs = new ThreadArgs(&handler, clientSocket);
        Task* task = new Task(handleThread, (void *) tArgs);
        tasks.push_back(task);
        pool->addTask(task);
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
    pool->terminate();
    int size = tasks.size();
    for (int i = 0; i < size; i++) {
        delete tasks[i];
    }
    delete pool;
    close(serverSocket);
}