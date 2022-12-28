#include<iostream>
using namespace std;
char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char turn = 'X';
int row,column;
bool draw = false;

void displayBoard(){
    system("clear");
    cout<<"\t\tT i c - T a c - T o e"<<endl;
    cout<<"Player[X]"<<endl<<"Player[O]"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
}


void playerChoice(){

    int choice;
    if (turn =='X')
    {
        cout<<"Player1[X] turn"<<endl;
    }
    else if (turn =='O')
    {
        cout<<"Player2[O] turn"<<endl;
    }
    
    cin>>choice;

    switch (choice)
    {
    case 1:row = 0, column = 0;break;
    case 2:row = 0, column = 1;break;
    case 3:row = 0, column = 2;break;
    case 4:row = 1, column = 0;break;
    case 5:row = 1, column = 1;break;
    case 6:row = 1, column = 2;break;
    case 7:row = 2, column = 0;break;
    case 8:row = 2, column = 1;break;
    case 9:row = 2, column = 2;break;
    
    default:
        cout<<"Invalid input"<<endl;
        break;
    }
    if (turn =='X' && board[row][column]!='X' && board[row][column]!='O')
    {
        board[row][column] = 'X';
        turn = 'O';
     }
    else if (turn =='O' && board[row][column]!='X' && board[row][column]!='O')
    {
        board[row][column] = 'O';
        turn = 'X';
     }
     else
    {
        cout<<"Box is already filled. Please try again!"<<endl;
        playerChoice();
    }
    displayBoard();
     
}

bool gameover(){
    //1. Check win
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] )
        {
            return false;
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] )
        {
            return false;
        }
        
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return false;
    }
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return false;
    }
    
    
    
    //2. Game in progress
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]!='X' && board[i][j]!='O')
            {
                return true;
            }
            
        }
        
    }
    
    
    //3. Game draw
    draw = true;
    return false;
}

int main(int argc, char const *argv[])
{
    
    
    while (gameover())
    {
    displayBoard();
    playerChoice();
    gameover();
    }
    
    if (turn == 'X' && draw == false)
    {
        cout<<"Player2[O] wins! Congratulations!"<<endl;
    }
    else if (turn == 'O' && draw == false)
    {
        cout<<"Player1[X] wins! Congratulations!"<<endl;
    }
    else
    {
        cout<<"Game Draw!!"<<endl;
    }
    return 0;
}
