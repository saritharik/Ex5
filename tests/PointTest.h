
#ifndef EX5_POINTTEST_H
#define EX5_POINTTEST_H
#include "../gtest_src/gtest.h"
#include "../include/Point.h"

class PointTest: public testing::Test {
public:
    PointTest();
    virtual void SetUp();
    virtual void TearDown();
};


#endif //EX5_POINTTEST_H
