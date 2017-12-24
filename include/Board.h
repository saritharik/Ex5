#ifndef EX5_BOARD_H
#define EX5_BOARD_H


class Board {
public:
    /**
     * Print the board.
     */
    virtual void printBoard() const = 0;
    /**
     * Return the specific square.
     * @param i the row.
     * @param j the col.
     * @return the square.
     */
    virtual char getSquare(int i, int j) = 0;
    /**
     * Set square in the specific location.
     * @param i the row.
     * @param j the col.
     * @param p the char.
     */
    virtual void setSquare(int i, int j, char p) = 0;
    /**
     * Return the dimensions of the board.
     * @return the dimensions.
     */
    virtual int getDimensions() = 0;
};


#endif //EX5_BOARD_H
