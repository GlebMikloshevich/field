#ifndef FIELD_H
#define FIELD_H

enum Cell
{
    EMPTY = 0,
    RED = 1,
    YELLOW = 2
};

class Field
{
private:

    const static int FIELD_WIDTH = 7;
    const static int FIELD_HEIGHT = 6;
    bool isRedTurn = true;
    Cell winner;
    Cell cells[FIELD_WIDTH][FIELD_HEIGHT];

public:

    Field(bool isRedFirst);
    void clear(bool isRedFirst);
    bool makeTurn(int column);
    bool isOver() const;
    bool isRedTurnNow() const;
    void print() const;
    void printResult() const;
    void checkWinner();
};
#endif //FIELD_H
