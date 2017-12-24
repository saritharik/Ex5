#include <iostream>
#include "../include/Game.h"
Game::Game(Player *p1, Player *p2, Board *b, GameLogic* game,
           UserInterface* userInter, bool remote):
        p1(p1), p2(p2), b(b), game(game), userInter(userInter), remoteGame(remote) {}

void Game::playGame() {
    bool player1 = true;
    int const startPoint = 2;
    p1->setPoint(startPoint);
    p2->setPoint(startPoint);
    int sum = ((this->b->getDimensions() - 1) * (this->b->getDimensions() - 1));
    Player *currentPlayer = p1;
    vector<Point>::iterator iter;
    while (p1->getPoint() + p2->getPoint() < sum) {
        userInter->startMove();
        this->b->printBoard();
        if (player1) {
            currentPlayer = p1;
        } else {
            currentPlayer = p2;
        }
        //if (count == 0) {
        //    currentPlayer = p1;
        //} else {
        //    currentPlayer = p2;
        //}
        Point point(-7, -7);
        vector<Point> vecPoints;
        if (remoteGame) {
            vecPoints = game->findPoints(currentPlayer->getDisk());

            if (vecPoints.empty()) {
                vector<Point> v1 = game->findPoints(this->p1->getDisk());
                vector<Point> v2 = game->findPoints(this->p2->getDisk());
                if (v1.empty() && v2.empty()) {
                    Point end(-1, -1);
                    vector<Point> endVec;
                    endVec.push_back(end);
                    point = currentPlayer->chooseSquare(endVec);
                    break;
                }
                point = currentPlayer->chooseSquare(vecPoints);
                player1 = !player1;

                continue;
            }
            point = currentPlayer->chooseSquare(vecPoints);
            if (point.getX() == -1 && point.getY() == -1) {
                break;
            }
            /*while ((!game->possibleMoves(point, currentPlayer->getDisk()))
                   || (point.getY() == 0 && point.getX() == 0)) {
                userInter->uncorrectMoves(vecPoints);
                point = currentPlayer->chooseSquare(vecPoints);
            }*/
        } else {
            userInter->currentPlayerMsg(currentPlayer->getDisk());
            vecPoints = game->findPoints(currentPlayer->getDisk());
            userInter->optionsToMove(vecPoints);
            if (vecPoints.empty()) {
                vector<Point> v1 = game->findPoints(this->p1->getDisk());
                vector<Point> v2 = game->findPoints(this->p2->getDisk());

                player1 = !player1;
                if (v1.empty() && v2.empty()) {
                    break;
                }
                continue;
            }
            point = currentPlayer->chooseSquare(vecPoints);
            while ((!game->possibleMoves(point, currentPlayer->getDisk()))
                   || (point.getY() == 0 && point.getX() == 0)) {
                userInter->uncorrectMoves(vecPoints);
                point = currentPlayer->chooseSquare(vecPoints);
            }
        }

            vector<Point> n1 = game->checking(point.getX(), point.getY(), currentPlayer->getDisk());
            vector<Point> n2 = game->checking(point.getX(), point.getY(), currentPlayer->getDisk());
            game->oneMove(point.getX(), point.getY(), currentPlayer->getDisk());
            if (player1) {
                p1->setPoint(1 + n1.size());
                game->setPlayerPoints(p1->getDisk(), p1->getPoint());
                p2->setPoint(-n1.size());
                game->setPlayerPoints(p2->getDisk(), p2->getPoint());
            } else {
                p2->setPoint(1 + n2.size());
                game->setPlayerPoints(p2->getDisk(), p2->getPoint());
                p1->setPoint(-n2.size());
                game->setPlayerPoints(p1->getDisk(), p1->getPoint());
            }
            cout << endl;
            player1 = !player1;
        }
        this->b->printBoard();
        if (p1->getPoint() > p2->getPoint()) {
            userInter->endOfGame(p1->getDisk());
        } else if (p2->getPoint() > p1->getPoint()) {
            userInter->endOfGame(p2->getDisk());
        } else {
            userInter->endOfGame(' ');
        }
    }
