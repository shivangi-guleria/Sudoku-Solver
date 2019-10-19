#include <iostream>
using namespace std;


bool checkrow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}


bool checkcol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}


bool checkblock(int grid[9][9], int boxStartRow,int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}



bool fillsudoku(int arr[9][9],int row, int col){
    if(row>=9 || col>=9){
        return true;
    }

    if (arr[row][col]==0){
        for(int i=1;i<=9;i++){
            if (!( (checkrow(arr,row,i)) || (checkcol(arr,col,i)) || (checkblock(arr,row-row%3,col-col%3,i)) )){
                arr[row][col]=i;
                if (fillsudoku(arr,row+col/8,(col+1)%9))
                    return true;
                arr[row][col]=0;
            }
        }
    }
    else
        return fillsudoku(arr,row+col/8,(col+1)%9);

return false;
}


bool sudokuSolver(int board[][9]){
    if (fillsudoku(board,0,0))
        return true;
    return false;
}

int main(){
    int board[9][9];
    for (int i =0;i<9;i++){
        for (int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }
    if (sudokuSolver(board)){
        for (int i =0;i<9;i++){
            for (int j=0;j<9;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
        cout<<"No possible solution exists.";
}