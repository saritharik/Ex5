//
// Created by sarit on 29/11/17.
//

#include "HumanTest.h"
HumanTest::HumanTest() {}
void HumanTest::SetUp() {}
void HumanTest::TearDown() {}

TEST_F(HumanTest, CheckGetDiskFunction) {
    Human check('O');
    EXPECT_EQ(check.getDisk(), 'O');
}
TEST_F(HumanTest, CheckGetPointFunction) {
    Human check('O');
    check.setPoint(10);
    EXPECT_EQ(check.getPoint(), 10);
}

TEST_F(HumanTest, CheckSetPointFunction) {
    Human check('O');
    check.setPoint(10);
    EXPECT_EQ(check.getPoint(), 10);
}