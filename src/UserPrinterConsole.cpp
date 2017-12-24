//
// Created by sarit on 29/11/17.
//

#include "../include/UserPrinterConsole.h"
#include <iostream>
using namespace std;

UserPrinterConsole::UserPrinterConsole() {}

void UserPrinterConsole::chooseRival() {
    cout << "Select your rival player:" << endl
         << "1 - Human player" << endl << "2 - AI player" << endl
            << "3 - Remote player" << endl;
}

void UserPrinterConsole::startMove() {
    cout << "Current board:" << endl;
}

void UserPrinterConsole::currentPlayerMsg(char disk) {
    cout << disk << ": it's your move." << endl;
}

void UserPrinterConsole::optionsToMove(vector<Point> points) {
    if (points.empty()) {
        cout << "No possible move. Play passes back to the other player."
                "Press any key + enter to continue.";
    } else {
        cout << "Your possible moves:";
        vector<Point>::iterator iter;
        for(iter = points.begin(); iter != points.end(); iter++) {
            cout << "(" << iter.base()->getX() << ", "
                 << iter.base()->getY() << ")";
        }
        cout << endl << endl;
        cout << "Please enter your move row,col: (example: x,y)";
    }
}

void UserPrinterConsole::uncorrectMoves(vector<Point> points) {
    cout << "This the possible moves:";
    vector<Point>::iterator iter;
    for(iter = points.begin(); iter != points.end(); iter++) {
        cout << "(" << iter.base()->getX() << ", "
             << iter.base()->getY() << ")";
    }
    cout << endl;
    cout << "Please enter your move row,col: (example: x,y)";
}

void UserPrinterConsole::endOfGame(char disk) {
    if (disk == 'X') {
        cout << "X is the winner!";
    } else if (disk == 'O') {
        cout <<  "O is the winner!";
    } else {
        cout << "The game ended in a draw";
    }
}

void UserPrinterConsole::remoteHelpPrinter() {
    cout << "Waiting for other player's move..." << endl;
}

void UserPrinterConsole::remotePlayerMsg(char disk, Point point) {
    if (disk == 'O') {
        cout << "O ";
    } else {
        cout << "X ";
    }
    cout << "played (" << point.getX() << "," << point.getY() << ")" << endl;
}