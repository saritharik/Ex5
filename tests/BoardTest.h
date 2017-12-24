
#ifndef EX5_BOARDTEST_H
#define EX5_BOARDTEST_H

#include "../gtest_src/gtest.h"
#include "../include/BoardConsole.h"

#include <iostream>
using namespace std;

class BoardTest: public testing::Test {
public:
    BoardTest();
    virtual void SetUp();
    virtual void TearDown();
};


#endif //EX5_BOARDTEST_H
