#include <iostream>
#include "../include/AI.h"

AI::AI(GameLogic* g, Board* b): board(b), game(g) {
    points = 0;
}

char AI::getDisk() {
    return 'O';
}

Point AI::chooseSquare(vector<Point> vecPoints) {
    int const startValue = 100;
    int min = startValue;
    Point choice(0,0);
    vector<Point> vec = game->findPoints(getDisk());
    vector<Point>::iterator iter;
    for (iter = vec.begin(); iter != vec.end(); iter++) {
        //put the current point on the board
        board->setSquare(iter.base()->getX(), iter.base()->getY(), getDisk());
        vector<Point> pointsToFlip = game->checking(iter.base()->getX(), iter.base()->getY(), getDisk());
        vector<Point>::iterator it;
        for (it = pointsToFlip.begin(); it != pointsToFlip.end(); it++) {
            game->replaceDisk(it.base()->getX(), it.base()->getY());
        }

        int max = maxOption();
        if (max < min) {
            min = max;
            choice = Point(iter.base()->getX(), iter.base()->getY());
        }
        //flip to the original state
        for (it = pointsToFlip.begin(); it != pointsToFlip.end(); it++) {
            game->replaceDisk(it.base()->getX(), it.base()->getY());
        }
        board->setSquare(iter.base()->getX(), iter.base()->getY(), ' ');
    }
    return choice;
}

int AI::maxOption() {
    int max = 0;
    int boardPoints = 0;
    int points;
    vector<Point> vec1 = game->findPoints('X');
    vector<Point>::iterator iter1;
    for (iter1 = vec1.begin(); iter1 != vec1.end(); iter1++) {
        points = game->checking(iter1.base()->getX(), iter1.base()->getY(), 'X').size();
        boardPoints = 1 + (2 * points) + game->getPointsByPlayer('X') - getPoint();
        if (boardPoints > max) {
            max = boardPoints;
        }
    }
    return boardPoints;
}

void AI::setPoint(int newPoints) {
    points += newPoints;
}

int AI::getPoint() {
    return points;
}