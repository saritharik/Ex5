#include "ThreadArgs.h"

 ThreadArgs::ThreadArgs(ClientHandler *handler, int socket):
         handler(handler), socket(socket) {}

ClientHandler* ThreadArgs::getHandler() {
    return this->handler;
}

int ThreadArgs::getSocket() {
    return this->socket;
}