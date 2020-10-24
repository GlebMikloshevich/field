//
//
//

#include <iostream>
#include "field.h"
#include <stdio.h>


const int DIR_NUMBER = 4;
const int di[] = { 1, 0, 1, 1 };
const int dj[] = { 0, 1, -1, 1 };
const int WIN_LENGTH = 4;

Field::Field(bool isRedFirst)
{
    clear(isRedFirst);
}

void Field::clear(bool isRedFirst)
{
    isRedTurn = isRedFirst;
    winner = EMPTY;
    for (int i=0; i<FIELD_WIDTH; i++)
        for(int j=0; j<FIELD_HEIGHT; j++)
            cells[i][j] = EMPTY;
}

bool Field::makeTurn(int column)
{
    if(winner != EMPTY || column < 1 || column > FIELD_WIDTH)
        return false;
    int i=column-1;
    for(int j=0; j<FIELD_HEIGHT; j++)
        if (cells[i][j] == EMPTY)
        {
            cells[i][j] = isRedTurn ? RED : YELLOW;
            checkWinner(); // Победа?
            isRedTurn = !isRedTurn;
            return true;
        }
    return false;
}

void Field::checkWinner()
{
    for(int i=0; i<FIELD_WIDTH; i++)
        for(int j=0; j<FIELD_HEIGHT; j++)
        {
            Cell start = cells[i][j];
            if (start==EMPTY)
                continue;
            for(int dir=0; dir<DIR_NUMBER; dir++)
            {
                int length=0,iline = i, jline = j;
                while(++length < WIN_LENGTH)
                {
                    iline += di[dir];
                    jline += dj[dir];
                    if (iline < 0 || iline >= FIELD_WIDTH || jline < 0 || jline >= FIELD_HEIGHT)
                        break;
                    if (cells[iline][jline] != start)
                        break;
                }
                if (length == WIN_LENGTH)
                {
                    winner = start;
                    return;
                }
            }
        }
}

bool Field::isOver() const
{
    if(winner != EMPTY)
        return true;
    for(int i=0; i<FIELD_WIDTH; i++)
        for(int j=0; j<FIELD_HEIGHT; j++)
            // Если хоть одна ячейка свободна,
            // игра не окончена
            if(cells[i][j]==EMPTY)
                return  false;
    // Все ячейки заняты
    return true;
}

void Field::print() const
{
    for (int i = FIELD_HEIGHT -1; i >=  0;  i--){
        for (int j = 0; j < FIELD_WIDTH; j++){

            if (cells[j][i] == 1)
                std::cout<<"\033[1;31mR \033[0m";
            else if (cells[j][i] == 2)
                std::cout<<"\033[1;33mY \033[0m";
            else
                std::cout<<"\033[1;37m0 \033[0m";
        }

        std::cout<<std::endl;
    }
}

bool Field::isRedTurnNow() const
{
    return (isRedTurn);
}


void Field::printResult() const
{
    print();
    if (winner == 1)
    {
        std::cout<<"\033[1;31mRed won\033[0m\n";
    } else {
        std::cout<<"\033[1;33mYellow won\033[0m\n";

    }
}














