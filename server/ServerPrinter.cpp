//
// Created by tamar on 11/12/17.
//

#include "ServerPrinter.h"
#include <iostream>
using namespace std;

void ServerPrinter::waitToConnection() {
    cout << "Waiting for client connections..." << endl;
}

void ServerPrinter::waitToOtherClient() {
    cout << "First client connected, wait to another client" << endl;
}

void ServerPrinter::connect() {
    cout << "Client connected" << endl;
}

void ServerPrinter::errorRead(char cord) {
    cout << "Error reading " << cord << " Point" << endl;

}

void ServerPrinter::disconnect() {
    cout << "Client disconnected" << endl;
}

void ServerPrinter::errorWrite() {
    cout << "Error writing to socket" << endl;
}