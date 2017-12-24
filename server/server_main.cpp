#include <iostream>
#include <cstdlib>
#include "Server.h"
#include <fstream>

using namespace std;
int main() {
    int port;
    char temp;
    ifstream reader;
    reader.open("../exe/serverSettings.txt");
    reader >> temp;
    while (temp != '=') {
        reader >> temp;
    }
    reader >> port;
    reader.close();
    Server server(port);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}