#ifndef EX5_THREADARGS_H
#define EX5_THREADARGS_H


#include "ClientHandler.h"

class ThreadArgs {
public:
    /**
     * Constructor.
     * @param handler - the ClientHandler.
     * @param socket - number of socket.
     */
    ThreadArgs(ClientHandler* handler, int socket);
    /**
     * Return pointer to client handler.
     * @return pointer to client handler.
     */
    ClientHandler* getHandler();
    /**
     * Return number of socket.
     * @return the socket.
     */
    int getSocket();

private:
    ClientHandler* handler;
    int socket;

};


#endif //EX5_THREADARGS_H
