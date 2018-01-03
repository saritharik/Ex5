#ifndef EX5_CLIENTHANDLER_H
#define EX5_CLIENTHANDLER_H

#include "CommandsManager.h"
#include "GameSettings.h"


class ClientHandler {
public:
    /**
     * Constructor.
     */
    ClientHandler();
    /**
     * Handle in client request.
     * @param socket - client socket.
     * @param command - the request.
     */
    void handleClient(int socket, string command);
    void closeSocket();
private:
    CommandsManager manager;
    vector<gameSettings> gameSet;
};


#endif //EX5_CLIENTHANDLER_H
