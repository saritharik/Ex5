#include "../include/BoardConsole.h"
#include <iostream>
using namespace std;

BoardConsole::BoardConsole(int row, int col): row(row + 1), col(col + 1){
    try {
        this->array = new char*[this->row];
        for(int i = 0; i < this->row; ++i)
            this->array[i] = new char[this->col];
    } catch (bad_alloc &ba) {
        cout << "Allocation failed";
    }

    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            this->array[i][j] = ' ';
        }
    }
    this->array[(this->row - 1) / 2][(this->row - 1) / 2] = 'O';
    this->array[(this->row + 1) / 2][(this->row + 1) / 2] = 'O';
    this->array[(this->row - 1) / 2][(this->row + 1) / 2] = 'X';
    this->array[(this->row + 1) / 2][(this->row - 1) / 2] = 'X';
}

BoardConsole::BoardConsole():row(9), col(9) {}

char BoardConsole::getSquare(int i, int j) {
    return this->array[i][j];
}

void BoardConsole::setSquare(int i, int j, char p) {
    this->array[i][j] = p;
}

int BoardConsole::getDimensions() {
    return this->row;
}

void BoardConsole::printBoard() const{
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            if (i == 0 && j != 0) {
                cout << j << " | ";
            } else if (j == 0 && i != 0) {
                cout << i << " | ";
            } else {
                cout << this->array[i][j] << " | ";
            }
        }
        cout << endl;
        for (int k = 0; k < (this->row * 4) - 1; k++) {
            cout << "-";
        }
        cout << endl;
    }
}

bool BoardConsole::operator ==(const BoardConsole& b1) const {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            if (this->array[i][j] != b1.array[i][j]) {
                return false;
            }
        }
    }
    return true;
}

BoardConsole::~BoardConsole() {
    for(int i = 0; i < this->row; ++i) {
        delete[] this->array[i];
    }
    delete[] this->array;
}