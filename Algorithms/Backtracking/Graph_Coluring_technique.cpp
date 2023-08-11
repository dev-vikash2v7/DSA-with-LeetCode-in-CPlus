
#include <iostream>

using namespace std;

#define N 4 

bool isSafe(bool graph[N][N],  int color[N] ,  int v , int  c ){
    
    for(int i = 0 ; i < N ; i++){
        if(graph[i][v] && color[i ] == c) return false ;
    }
    
    return true ;
}

bool graphColoring(bool graph[N][N], int m, int v , int color[N]){
            
        if(v == N) {
            return true;
        }
        
        for(int c = 1 ; c <= m ; c++){
            
            if(isSafe(graph , color , v , c)){
                
            color[v] = c ;  
            
            if(graphColoring(graph , m , v + 1 , color))
                return true ;
                
            color[v] = 0 ;
            }
        }
return false ;        
        
}
int main()
{
    int m = 3 ; 
     bool graph[N][N] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    
    int color[N] = {0} ;
    
     if (!graphColoring(graph, m, 0, color))
        cout << "Solution does not exist";
 else{
     for(int i = 0 ; i < N  ; i++ ){
         cout<< color[i] << endl;
     }
 }
    return 0;
}