
// CPP program to find shortest distance
// in a multistage graph.
#include<bits/stdc++.h>
using namespace std;

#define N 8 
#define Stages 4 
#define INF INT_MAX

int shortestDist(int dist[N][N]){
    int dest[N+1], cost[N+1] , path[Stages+1];
    
    cost[N] = 0 ;      dest[N] = N ;
    
    for(int v = N-1 ; v >= 1 ;v--){
        
        int current_cost = INF ;
        
        for(int k = v + 1 ; k <= N ; k++){
                              
            if(dist[v-1][k-1] != INF){
                if( dist[v-1][k-1] + cost[k] < current_cost){
                    current_cost = dist[v-1][k-1] + cost[k];
                    dest[v] = k ; 
                }
            }
        }
        cost[v] = current_cost ;
    }
    
    path[0] = 1 ;
    for(int i = 1 ; i<Stages ; i++){
        path[i] = dest[path[i-1]];
    }
     for(int i = 0 ; i<Stages ; i++){
        cout << path[i] << " --> ";
    }
    cout << endl ;
    
    return cost[1];
        
}


int main()
{
     int graph[N][N] =
      {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2},
      {INF, INF, INF, INF, INF, INF, INF, INF}};
 
    cout << shortestDist(graph);
    

    return 0;
}