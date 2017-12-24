
#ifndef EX5_GAMELOGICTEST_H
#define EX5_GAMELOGICTEST_H
#include "../gtest_src/gtest.h"
#include "../include/GameLogic.h"
#include <iostream>
using namespace std;

class GameLogicTest: public testing::Test {
public:
    GameLogicTest();
    virtual void SetUp();
    virtual void TearDown();
};


#endif //EX5_GAMELOGICTEST_H