//
// Created by sarit on 29/11/17.
//

#include "PointTest.h"
PointTest::PointTest() {}
void PointTest::SetUp() {}
void PointTest::TearDown() {}

TEST_F(PointTest, CheckGetXFunction) {
    Point check(2,5);
    EXPECT_EQ(check.getX(), 2);
}

TEST_F(PointTest, CheckGetYFunction) {
    Point check(2,5);
    EXPECT_EQ(check.getY(), 5);
}