
#ifndef EX5_AITEST_H
#define EX5_AITEST_H
#include "../gtest_src/gtest.h"
#include "../include/AI.h"

class AITest: public testing::Test {
public:
    AITest();
    virtual void SetUp();
    virtual void TearDown();

};


#endif //EX5_AITEST_H
