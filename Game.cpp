#include<bits/stdc++.h>
using namespace std;
#define n 3
#define player1 1
#define player2 2

void startGame(char board[n][n], int moves[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            board[i][j] = ' ';
    }

    for(int i=1; i<=n*n; i++)
        moves[i] = i;

}

void showBoard(char board[n][n])
{
    cout <<"\n\n";
    cout <<"\t\t\t      " <<board[0][0] <<"  |  " <<board[0][1] <<"  |  " <<board[0][2] <<endl;
    cout <<"\t\t\t      "  <<"--------------" <<endl;
    cout <<"\t\t\t      " <<board[1][0] <<"  |  " <<board[1][1] <<"  |  " <<board[1][2] <<endl;
    cout <<"\t\t\t      "  <<"--------------" <<endl;
    cout <<"\t\t\t      " <<board[2][0] <<"  |  " <<board[2][1] <<"  |  " <<board[2][2] <<endl;
    cout <<"\n\n";
}

bool rowCrossed(char board[n][n])
{
    for(int i=0; i<n; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
    }
    return false;
}

bool columnCrossed(char board[n][n])
{
    for(int i=0; i<n; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }
    return false;
}

bool diagonalCrossed(char board[n][n])
{
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;
    
    return false;
}

bool gameOver(char board[n][n])
{
    if(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board))
        return true;
    else
        return false;
}

void declareWinner(int turn)
{
    if(turn == player1)
        cout <<"Congratulations player1, you have won the game..." <<"\n\n";
    else 
        cout <<"Congratulations player2, you have won the game..." <<"\n\n";
}

void Playgame(int turn)
{
    char board[n][n];
    int moves[n*n];

    startGame(board,moves);

    int moveindex = 0;
    int index;
    int x,y;

    while(gameOver(board) == false && moveindex != n*n)
    {
        if(turn == player1)
        {
            cout <<"Player1, Enter cell no. where you want to put your coin..." <<" ";
            cin >> index;
            x = moves[index] / n;
            y = moves[index] % n - 1;
            board[x][y] = 'O';
            showBoard(board);
            moveindex++;
            turn = player2;
        }

        else if(turn == player2)
        {
            cout <<"Player2, Enter cell no. where you want to put your coin..." <<" ";
            cin >> index;
            x = moves[index] / n;
            y = moves[index] % n - 1;
            board[x][y] = 'X';
            showBoard(board);
            moveindex++;
            turn = player1;
        }
    }

    if(gameOver(board) == false && moveindex == n*n)
        cout <<"It's a draw..." <<"\n\n";
    else
    {
        if(turn == player1)
            turn = player2;
        else if(turn == player2)
            turn = player1;

        declareWinner(turn);
    }
    return ;
}

int main()
{
    cout <<"\n\n";
    cout <<"\t\t\t      " <<"Welcome To Ultimate Tic-Tac-Toe Game" <<endl;
    cout <<"\t\t\t           " <<"Created By: Tushar Lalawat" <<"\n\n";
    cout <<"\t\t\t______________________________________________________ " <<"\n\n";

    cout <<"Enter a cell no. from 1 to 9 as showen below..." <<endl;
    cout <<"\n\n";
    cout <<"\t\t\t      " <<" 1  |  2  |  3" <<endl;
    cout <<"\t\t\t      " <<"---------------" <<endl;
    cout <<"\t\t\t      " <<" 4  |  5  |  6" <<endl;
    cout <<"\t\t\t      " <<"---------------" <<endl;
    cout <<"\t\t\t      " <<" 7  |  7  |  9" <<endl;
    cout <<"\n\n";
    Playgame(player1);
}