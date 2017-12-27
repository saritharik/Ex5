#ifndef EX5_CLOSECOMMAND_H
#define EX5_CLOSECOMMAND_H


#include "Command.h"

class CloseCommand: public Command {
public:
    CloseCommand();
    virtual void execute(int clientSocket, vector<string> args);

};


#endif //EX5_CLOSECOMMAND_H
