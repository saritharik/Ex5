//
// Created by tamar on 28/11/17.
//

#include "BoardTest.h"
BoardTest::BoardTest() {}
void BoardTest::SetUp() {}
void BoardTest::TearDown() {}

TEST_F(BoardTest, CheckGetSquareFunction) {
    BoardConsole b(8, 8);
    EXPECT_EQ(b.getSquare(4,4), 'O');
    EXPECT_EQ(b.getSquare(4,5), 'X');
}

TEST_F(BoardTest, checkSetSquareFunction) {
    BoardConsole b(8,8);
    b.setSquare(2, 2, 'X');
    EXPECT_EQ(b.getSquare(2, 2), 'X');
}

TEST_F(BoardTest, checkGetDimentionFunc) {
    BoardConsole b(8, 8);
    EXPECT_EQ(b.getDimensions(), 9);
}

TEST_F(BoardTest, checkEqualBoards) {
    BoardConsole b1(4,4);
    BoardConsole b2(4,4);
    EXPECT_EQ(b1, b2);
}