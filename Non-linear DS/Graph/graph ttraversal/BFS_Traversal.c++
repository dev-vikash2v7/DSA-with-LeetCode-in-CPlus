#include <bits/stdc++.h>

using namespace std;

class Graph{
    private :
        int n_vertices  ;
        vector<list<int>>graph ;

    public:
        Graph(int n ) : n_vertices(n) {
            graph.resize(n);
        }

        void addEdge(int u , int v){
                graph[u].push_back(v);
         }


        void showGraph(){

        for (int v = 0; v < n_vertices; ++v) {
                        cout << v << "  :  " ; 

                for(auto x : graph[v]){
                        cout << x << " " ; 
                    }
                        cout << endl;
            }

        }

        void BFS(int root_vertex){
           

             // Mark all the vertices as not visited
        vector<bool> visited;
        visited.resize(n_vertices, 0);
    
        // Create a queue for BFS
        list<int> queue;

        queue.push_back(root_vertex);
        visited[root_vertex] = 1 ;

        while (!queue.empty())
        {
                // Dequeue a vertex from queue and print it
            root_vertex = queue.front() ;
            queue.pop_front() ; 


            cout << root_vertex << " " ;

  // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
            for(auto adjecent: graph[root_vertex]){
                if(!visited[adjecent]){
                    visited[adjecent] = 1 ; 
                    queue.push_back(adjecent);
                }
            }
        }
cout << endl;

        }




// Below is the implementation for BFS traversal for the entire graph (valid for directed as well as undirected graphs) with possible multiple 
//disconnected components:
        vector<int> bfsOfGraph()
        {
        vector<int> bfs_traversal;
        vector<bool> vis(n_vertices, false);

        for (int i = 0; i < n_vertices; ++i) {
    
            // To check if already visited
            if (!vis[i]) {
                queue<int> q;
                vis[i] = true;
                q.push(i);
 
            // BFS starting from ith node
            while (!q.empty()) {
                int g_node = q.front();
                q.pop();
                bfs_traversal.push_back(g_node);
                for (auto it : graph[g_node]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfs_traversal;
}
};

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,4);

    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);

    g.addEdge(2,1);
    g.addEdge(2,3);

    g.addEdge(3,1);
    g.addEdge(3,2);
    g.addEdge(3,4);

    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(4,3);

    g.showGraph();
    
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n";
    g.BFS(0) ;

  for(auto x :  g.bfsOfGraph() ){
    cout << x << " " ; 
  } ;
return 0;
}

// Time Complexity: O(V+E), where V is the number of nodes and E is the number of edges.
// Auxiliary Space: O(V)

//  0----1\                   0 : 1 -> 4
//  |   /| \                  1 : 0 -> 4 -> 3 -> 2
//  |  / |   2 ------------>  2 : 1 -> 3
//  | /  | /                  3 : 1-> 2-> -> 4
//  4----3/                   4 : 0 -> 1 -> 3

//BFS : 0 1  4 2  3

//visited = [ 0 , 0 , 0 , 0 , 0]
//queue = [ 0 ]

