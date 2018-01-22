#ifndef EX5_SERVER_H
#define EX5_SERVER_H

#include "ServerPrinter.h"
#include "ClientHandler.h"
#include "ThreadArgs.h"
#include "ThreadPool.h"

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

    /**
     * Handle clients.
     * @param handle - client details.
     * @return - void.
     */
    static void *handleThread(void *handle);

    /**
     * hread of he server
     * @param server get a refernce to the server
     * @return nothing
     */
    static void *startThread(void *server);


private:
    int port;
    int serverSocket; // the socket's file descriptor
    ServerPrinter printer;
    ClientHandler handler;
    vector<Task *> tasks;
    //vector<pthread_t> threads;
    ThreadPool pool;
};


#endif //EX5_SERVER_H
