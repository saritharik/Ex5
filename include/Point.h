#ifndef EX5_POINT_H
#define EX5_POINT_H


class Point {
public:
    /**
     * Constuctor.
     * @param x the x value.
     * @param y the y value.
     */
    Point(int x, int y);
    /**
     * Return the x value.
     * @return the x.
     */
    int getX();
    /**
     * Return the y value.
     * @return the y.
     */
    int getY();
    /**
     * Set x value.
     * @param x - new value.
     */
    void setX(int x);
    /**
     * Set y value.
     * @param y - new value.
     */
    void setY(int y);
private:
    int x, y;
};


#endif //EX5_POINT_H
