#ifndef EX5_COMMAND_H
#define EX5_COMMAND_H

#include <vector>
#include <string>
using namespace std;
class Command {
public:
    /**
     * Execute the relevant command.
     * @param clientSocket - num of socket.
     * @param args - arguments.
     */
    virtual void execute(int clientSocket, vector<string> args) = 0;
    /**
     * D'tor.
     */
    virtual ~Command() {}
};
#endif //EX5_COMMAND_H
