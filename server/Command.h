#ifndef EX5_COMMAND_H
#define EX5_COMMAND_H

#include <vector>
#include <string>
using namespace std;
class Command {
public:
    virtual void execute(int clientSocket, vector<string> args) = 0;
    virtual ~Command() {}
};
#endif //EX5_COMMAND_H
