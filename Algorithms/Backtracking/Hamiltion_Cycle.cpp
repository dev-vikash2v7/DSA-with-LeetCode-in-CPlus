/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
#define N 5


bool isSafe(int graph[N][N] ,int path[N] , int v ,int pos){
      /* Check if this vertex is an adjacent
    vertex of the previously added vertex. */
    if(graph[path[pos-1]][v] == false  ) return false ;
    
        /* Check if the vertex has already been included.
    This step can be optimized by creating
    an array of size V */
    for(int i =0 ; i < pos ; i++)
        if(path[i] == v) return false ;
    return true ;
}

bool hamCycle(int graph[N][N] ,int path[N] , int pos)
{
    
    if(pos == N){
        if(graph[path[N-1]][path[0]] == 1) return true ;
        return false ;
    }
   
   for(int v = 1 ; v < N ; v++){
       if(isSafe(graph , path , v , pos)){
           path[pos] = v ;
           if(hamCycle(graph , path , pos+1)){
               return true ;
           }
           
           path[pos] = -1 ;
       }
   }
   
   return false ;
   
}
void printSolution(int path[])
{
    cout << "Solution Exists:"
            " Following is one Hamiltonian Cycle \n";
    for (int i = 0; i < N; i++)
        cout << path[i] << " ";
 
    // Let us print the first vertex again
    // to show the complete cycle
    cout << path[0] << " ";
    cout << endl;
}

int main()
{
     int path[N] = {-1};
     path[0] = 0 ;
    /* Let us create the following graph
        (0)--(1)--(2)
        | / \ |
        | / \ |
        | / \ |
        (3)-------(4) */
    int graph1[N][N] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
     
    // Print the solution
    
    int pos = 1 ;
    
    if (    hamCycle(graph1, path, pos)== false )
    {
        cout << "\nSolution does not exist";
       
    }
 else
    printSolution(path);
;
     

    return 0;
}