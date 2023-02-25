#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

int num = 1;
int size = 0;

void create_board(int board[][5], int row, int col){
    for (int i=0; i < row; i++){
        for (int j=0; j < col; j++){
            board[i][j] = 0;
            size++;
        }
    }
}

void print_board(int board[][5], int row, int col){
    std::cout << "[0;0H\n";

    for (int i=0; i < row; i++){
        for (int j=0; j <col; j++){
            if (board[i][j] < 10){
                std::cout << board[i][j] << "   ";
            }
            else{
                std::cout << board[i][j] << "  ";
            }
        }
        std::cout << "\n";
    }
}


void solve(int board[][5], int num, int row, int col,bool &solved) {
    if (num > size){
        solved = true;
        return;
    }

    if (row<0 || row>=5 || col<0 || col>=5){ // out of bounds for board
        return;
    }

    if (board[row][col]==0){
        board[row][col] = num;
        num++;
        usleep(50000);
        print_board(board,5,5);
    }
    else{
        return;
    }

    if (!solved) solve(board,num,row-2,col+1, solved); // 1
    if (!solved) solve(board,num,row-1,col+2, solved); // 2
    if (!solved) solve(board,num,row+1,col+2, solved); // 3
    if (!solved) solve(board,num,row+2,col+1, solved); // 4
    if (!solved) solve(board,num,row+2,col-1, solved); // 5
    if (!solved) solve(board,num,row+1,col-2, solved); // 6
    if (!solved) solve(board,num,row-1,col-2, solved); // 7
    if (!solved) solve(board,num,row-2,col-1, solved); // 8

    if (!solved) board[row][col] = 0;
}


int main()
{
    int board[5][5];
    bool solved = false;

    create_board(board,5,5);
    print_board(board,5,5);
    solve(board,num,0,0,solved); // starting at (0,0)
    return 0;
}
