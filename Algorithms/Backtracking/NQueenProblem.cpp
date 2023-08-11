
#include <iostream>

using namespace std;

#define N 8

bool isSafe(int board[N][N], int row, int col);
bool solveNQueen(int board[N][N], int row);
void printSolution(int board[N][N]);

bool isSafe(int board[N][N] ,int row , int col  ){
    
    // check for not have any upward queen
    for(int i = 0  ;i < row ; i++)
        if(board[i][col] == 1) return false ;
    
    
    // check for not have any upward-left queen
     for(int i = row-1 , j = col-1;  i >= 0 && j >= 0 ; j-- , i--)
            if(board[i][j] == 1) return false ;
    
                                                      
    // check for not have any upward-right queen
     for(int i = row -1  , j = col + 1 ; j < N  && i >= 0 ; j ++ , i--)
                if(board[i][j] == 1) return false ;
     
    return true ;
};


bool solveNQueen( int board[N][N] , int row){
    
    // if all queens place
    if(row >= N) return true ;
    
    
    for(int col = 0 ; col < N ;col++){
        
        if( isSafe(board ,row , col ) ){
            board[row][col] = 1 ;
            
            if(solveNQueen( board , row + 1) ){
                    return true ;
                }
            board[row][col] = 0 ;
        }
    }
    
    return false ;
};


void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
           if(board[i][j])
            cout << "Q ";
           else cout<<". ";
        printf("\n");
    }
}
 


int main()
{

int board[N][N] ; 
                        
                    
                        
if(solveNQueen( board , 0)){
    printSolution(board);
}
else{
    cout << "no solution for this !!!!";
}
    return 0;
}
