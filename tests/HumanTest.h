
#ifndef EX5_HUMANTEST_H
#define EX5_HUMANTEST_H
#include "../gtest_src/gtest.h"
#include "../include/Human.h"

class HumanTest: public testing::Test {
public:
    HumanTest();
    virtual void SetUp();
    virtual void TearDown();
};


#endif //EX5_HUMANTEST_H
