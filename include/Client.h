#ifndef EX5_CLIENT_H
#define EX5_CLIENT_H

#include "Point.h"

class Client {
public:
    /**
     * Constuctor.
     * @param serverIP - the IP address.
     * @param serverPort - number of port.
     */
    Client(const char *serverIP, int serverPort);
    /**
     * Connect to server.
     * @return the disk of player that connect to server.
     */
    char connectToServer();
    /**
     * Return message from the server.
     * @return the point that the other player choose.
     */
    Point getMessage();
    /**
     * Send message to server.
     * @param newPoint the point that choosen.
     */
    void sendMessage(Point newPoint);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};
#endif //EX5_CLIENT_H
