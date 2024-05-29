#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define N 4

int board[N][N];
bool isSafe(int row,int col){
    int i,j;
    //check this row on left side
    for(i=0;i<col;i++){
        if(board[row][i]) return false;
    }

    //check upper diagonal on left side
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]) return false;
    }
    //check lower diagonal on left side
    for(i=row,j=col;j>=0 && i<N;i++,j--){
        if(board[i][j]) return false;
    }

    //we are checking all left side because we are filling it up column by column => thus we check only prev positions
    return true;
}

bool solveNQUtil(int col){
    //base case: if all queens are placed then returns true
    if(col >= N) return true;

    //consider given col in parameter and check for all rows one by one i=row
    for(int i=0;i<N;i++){
        if(isSafe(i,col)){
            board[i][col]=1; //if it's safe then place it in the given row and col

            if(solveNQUtil(col+1)) return true; //RECUR to place rest of the queens

            //if placing queen in board[i][col] doesnt lead to a solution then remove queen from board[i][col]
            board[i][col]=0; //BACKTRACK
        }
    }
    //if queen cannot be placed in any row for the given col then return false
    return false;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}


int main(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]=0;
        }
        if(solveNQUtil(0)==false){
            printf("No solution exists");
        }
        //printSol();
        printSolution();
        return 0;
    }
}