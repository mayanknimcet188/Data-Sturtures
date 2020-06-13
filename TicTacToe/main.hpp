#include<iostream>
using namespace std;

class Tictactoe
        {
        char gameboard[4][4];
        public:
            Tictactoe();
        void setGridValue(int row,int column,char input);
        char getGridValue(int row,int column);
        int checkRow(char input);
        int checkColumn(char input);
        int checkDiagonal(char input);
        void printInfo();
        };

Tictactoe::Tictactoe()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            gameboard[i][j]='-';
        }
    }
}
void Tictactoe::setGridValue(int row,int column, char input) {
    gameboard[row][column]=input;
}
char Tictactoe::getGridValue(int row, int column) {
    return gameboard[row][column];
}
int Tictactoe::checkRow(char input) {
    for(int i=0;i<4;i++)
    {
        int count=0;
        for(int j=0;j<4;j++) {
            if (gameboard[i][j] == input) {
                count++;
            }
            if (count == 4) return 1;
        }
    }
    return 0;
}
int Tictactoe::checkColumn(char input) {
    for(int i=0;i<4;i++)
    {
        int count=0;
        for(int j=0;j<4;j++)
        {
            if(gameboard[j][i] == input)
            {
                count++;
            }
            if(count==4) return 1;
        }
    }
    return 0;
}
int Tictactoe::checkDiagonal(char input) {
    int count=0;
    for(int i=0;i<4;i++)
    {

        if(gameboard[i][i] == input)
        count++;
    }
    if(count==4) return 1;
    else return 0;
}
void Tictactoe::printInfo() {
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<gameboard[i][j]<<"\t";
        }
        cout<<"\n";
    }
}