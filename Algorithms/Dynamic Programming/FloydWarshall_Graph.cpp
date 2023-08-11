
#include <iostream>

using namespace std;

#define V 4
#define INF 99999


/* A utility function to print solution */
void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}
 


void floydWarshall(int cost[V][V]){
    
    for(int k = 0 ; k < V ; k++){
         for(int i = 0 ; i < V ; i++){
             for(int j = 0 ; j < V ; j++){
                    cost[i][j] = min(cost[i][j] , cost[i][k] + cost[k][j]);
            }
        }
    }
    
    printSolution(cost);
}


int main()
{
    /* Let us create the following weighted graph
            10
    (0)------->(3)
        |     /|\
    5 |     |
        |     | 1
    \|/     |
    (1)------->(2)
            3     */
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    // Function call
    floydWarshall(graph);
    return 0;
}