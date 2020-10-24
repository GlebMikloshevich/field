#include <iostream>
#include "field.h"

using namespace std;

int main(void)
{

    setlocale(LC_ALL, "Russian");
    Field field(true);
    while(!field.isOver())
    {
        field.print();
        //"\033[1;31mкрасный\033[0m"
        //1;31  || 1 - жирный/ 0 - обычный || 31 - красный/ 33 - желтый; красный - текст для формтирования
        cout<<"Ходит "<<(field.isRedTurnNow() ? "\033[1;31mкрасный\033[0m" : "\033[1;33mжелтый\033[0m")<<" игрок, введите столбец (1-7)"<<endl;
        int column;
        cin>>column;
        field.makeTurn(column);
        //добавить обработку только трех кнопок. (0/1/2)
    }
    field.printResult();
    return 0;
}
