//
// Created by sarit on 29/11/17.
//

#include "AITest.h"
AITest::AITest() {}
void AITest::SetUp() {}
void AITest::TearDown() {}

TEST_F(AITest, CheckGetDiskFunction) {
    BoardConsole bC(8, 8);
    GameLogic gameLogic(&bC);
    AI check(&gameLogic, &bC);
    EXPECT_EQ(check.getDisk(), 'O');
}

TEST_F(AITest, CheckGetPointFunction) {
    BoardConsole bC(8, 8);
    GameLogic gameLogic(&bC);
    AI check(&gameLogic, &bC);
    check.setPoint(10);
    EXPECT_EQ(check.getPoint(), 10);
}

TEST_F(AITest, CheckSetPointFunction) {
    BoardConsole bC(8, 8);
    GameLogic gameLogic(&bC);
    AI check(&gameLogic, &bC);
    check.setPoint(10);
    EXPECT_EQ(check.getPoint(), 10);
}
