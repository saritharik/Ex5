//
// Created by tamar on 29/11/17.
//

#include "GameLogicTest.h"
GameLogicTest::GameLogicTest() {}
void GameLogicTest::SetUp() {}
void GameLogicTest::TearDown() {}

TEST_F(GameLogicTest, CheckReplaceDiskFunc) {
    BoardConsole board(8, 8);
    GameLogic gameLogic(&board);
    gameLogic.replaceDisk(4, 4);
    EXPECT_EQ(board.getSquare(4, 4), 'X');
}
