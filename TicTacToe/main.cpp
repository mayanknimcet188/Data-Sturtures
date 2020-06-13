#include "main.hpp"

int main()
{
    Tictactoe game;
    string user1,user2;
    cout<<"Please enter the name of the first player: ";
    cin>>user1;
    cout<<"\nPlease enter the name of the second player: ";
    cin>>user2;
    for(int i=0;i<8;i++)
    {
        int row=0,column=0;
        cout<<user1<<" Please enter the grid value: ";
        cin>>row>>column;

        if(game.getGridValue(row,column)=='-')
        {game.setGridValue(row,column,'x');}
        if(game.checkRow('x') || game.checkColumn('x') || game.checkDiagonal('x'))
        {
            cout<<" Congratulations "<<user1<<" you have won the game!!";
            break;
        }
        cout<<"\n";
        game.printInfo();
        cout<<user2<<" Please enter the grid value: ";
        cin>>row>>column;
        if(game.getGridValue(row,column)=='-')
        {game.setGridValue(row,column,'o');}
        if(game.checkRow('o') || game.checkColumn('o') || game.checkDiagonal('o'))
        {
            cout<<" Congratulations "<<user2<<" you have won the game!!";
            break;
        }
        cout<<"\n";
        game.printInfo();
    }
    return 0;
}
