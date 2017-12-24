#include "../include/GameLogic.h"
#include <iostream>
using namespace std;

GameLogic::GameLogic(Board* b): b(b) {
    int const startPoint = 2;
    this->oPoints = startPoint;
    this->xPoints = startPoint;
}

bool GameLogic::possibleMoves(Point p, char a) {
    bool b = false;
    vector<Point>::iterator iter;
    vector<Point> v = findPoints(a);
    for(iter = v.begin(); iter != v.end(); iter++) {
        if ((iter.base()->getX() == p.getX()) &&
                iter.base()->getY() == p.getY()) {
            b = true;
            break;
        }
    }
    return b;

}
void GameLogic::replaceDisk(int i, int j) {
    char a = this->b->getSquare(i,j);
    if (a == 'X') {
        this->b->setSquare(i, j, 'O');
    }
    if (a == 'O') {
        this->b->setSquare(i, j, 'X');
    }
}
void GameLogic::oneMove(int i, int j, char a) {
    this->b->setSquare(i, j, a);
    vector<Point> vec = this->checking(i, j, a);
    vector<Point>::iterator it;
    for(it = v.begin(); it != v.end(); it++) {
        this->replaceDisk(it.base()->getX(),it.base()->getY());
    }
    this->v.clear();
}

vector<Point> GameLogic::findPoints(char a) {
    vector<Point> points;
    vector<Point> check;
    vector<Point>::iterator iter;
    for (int i = 1; i < this->b->getDimensions(); i++) {
        for (int j = 1; j < this->b->getDimensions(); j++) {
            if (this->b->getSquare(i, j) == ' ') {
                check = this->checking(i, j, a);
                if (check.size() != 0) {
                    points.push_back(Point(i, j));
                    check.clear();
                    this->v.clear();
                }

            }
        }
    }
    return points;
}

vector<Point> GameLogic::checking(int i, int j, char a) {
    vector<Point>::iterator it;
    int row = i; int col = j;
    char self = a, other;
    vector<Point> vecTemp;
    if (self == 'X') {
        other = 'O';
    } else {
        other = 'X';
    }
    while (i - 1 > 0) {
        if (this->b->getSquare(i-1, j) != ' ' &&
            this->b->getSquare(i-1, j) == other) {
            vecTemp.push_back(Point(i-1, j));
            i--;
        } else {
            if (this->b->getSquare(i - 1,j) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j - 1 > 0) {
        if (this->b->getSquare(i, j-1) != ' ' &&
            this->b->getSquare(i, j-1) == other) {
            vecTemp.push_back(Point(i, j-1));
            j--;
        } else {
            if (this->b->getSquare(i,j - 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (i + 1 < this->b->getDimensions()) {
        if (this->b->getSquare(i+1, j) != ' ' &&
            this->b->getSquare(i+1, j) == other) {
            vecTemp.push_back(Point(i+1, j));
            i++;
        } else {
            if (this->b->getSquare(i + 1,j) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j + 1 < this->b->getDimensions()) {
        if (this->b->getSquare(i, j+1) != ' ' &&
            this->b->getSquare(i, j+1) == other) {
            vecTemp.push_back(Point(i, j+1));
            j++;
        } else {
            if (this->b->getSquare(i,j + 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j + 1 < this->b->getDimensions() &&
            i + 1 < this->b->getDimensions()) {
        if (this->b->getSquare(i+1, j+1) != ' ' &&
            this->b->getSquare(i+1, j+1) == other) {
            vecTemp.push_back(Point(i+1, j+1));
            j++; i++;
        } else {
            if (this->b->getSquare(i + 1,j + 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j + 1 < this->b->getDimensions() &&
           i - 1 > 0) {
        if (this->b->getSquare(i-1, j+1) != ' ' &&
            this->b->getSquare(i-1, j+1) == other) {
            vecTemp.push_back(Point(i-1, j+1));
            j++; i--;
        } else {
            if (this->b->getSquare(i - 1,j + 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j - 1 > 0 && i - 1 > 0) {
        if (this->b->getSquare(i-1, j-1) != ' ' &&
            this->b->getSquare(i-1, j-1) == other) {
            vecTemp.push_back(Point(i-1, j-1));
            j--; i--;
        } else {
            if (this->b->getSquare(i - 1,j - 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j - 1 > 0 &&
           i + 1 < this->b->getDimensions()) {
        if (this->b->getSquare(i+1, j-1) != ' ' &&
            this->b->getSquare(i+1, j-1) == other) {
            vecTemp.push_back(Point(i+1, j-1));
            j--; i++;
        } else {
            if (this->b->getSquare(i + 1,j - 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    return this->v;
}

void GameLogic::setPlayerPoints(char player, int points) {
    if (player == 'X') {
        xPoints = points;
    } else if (player == 'O') {
        oPoints = points;
    }
}

int GameLogic::getPointsByPlayer(char player) {
    if (player == 'X') {
        return xPoints;
    } else {
        return oPoints;
    }
}