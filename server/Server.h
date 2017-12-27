#ifndef EX5_SERVER_H
#define EX5_SERVER_H


#include "../include/Point.h"
#include "ServerPrinter.h"
#include "ClientHandler.h"

class Server {
public:
    /**
     * Constructor
     * @param port - number of port.
     */
    Server(int port);
    /**
     * Start the connection.
     */
    void start();
    /**
     * Stop the connection.
     */
    void stop();
    //void *whileLoop
private:
    int port;
    int serverSocket; // the socket's file descriptor
    void handleClient(int clientSocketX, int clientSocketO);
    ServerPrinter printer;
    ClientHandler handler;
};


#endif //EX5_SERVER_H
