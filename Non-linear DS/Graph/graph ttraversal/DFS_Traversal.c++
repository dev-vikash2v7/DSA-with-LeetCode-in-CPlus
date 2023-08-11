#include <bits/stdc++.h>

using namespace std;

class Graph{
    private :
        int n_vertices  ;
        vector<list<int>>graph ;
        vector<int> visited;

    public:
        Graph(int n ) : n_vertices(n) {
            graph.resize(n);
            visited.resize(n_vertices, 0);
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

        void DFS_with_stack(int root_vertex){
           
        // Create a queue for BFS
        stack<int> stack;

        stack.push(root_vertex);
        visited[root_vertex] = 1 ;

        while (!stack.empty())
        {
                // pop a vertex from stack and print it
            root_vertex = stack.top() ;
            stack.pop() ; 

            cout << root_vertex << " " ;

  // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
            for(auto adjecent: graph[root_vertex]){
                if(!visited[adjecent]){
                    visited[adjecent] = 1 ; 
                    stack.push(adjecent);
                }
            }
        }
        cout << endl;
        }



        void DFS_with_recursion(int root_vertex){
        
            visited[root_vertex] = 1 ;

            cout << root_vertex << " " ;

// Recur for all the vertices adjacent
    // to this vertex
            for(auto adjecent: graph[root_vertex]){
                if(!visited[adjecent]){
                    DFS_with_recursion(adjecent);
                }
            }

        }




};

int main()
{
    Graph g(4);

    // g.addEdge(0,1);
    // g.addEdge(0,4);

    // g.addEdge(1,0);
    // g.addEdge(1,2);
    // g.addEdge(1,4);

    // g.addEdge(2,1);
    // g.addEdge(2,3);

    // g.addEdge(3,2);
    // g.addEdge(3,4);

    // g.addEdge(4,0);
    // g.addEdge(4,1);
    // g.addEdge(4,3);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.showGraph();
    
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS_with_recursion(2) ;
    // g.DFS_with_stack(2) ;

//   for(auto x :  g.dfsOfGraph() ){
//     cout << x << " " ; 
//   } ;
return 0;
}

// Time Complexity: O(V+E), where V is the number of nodes and E is the number of edges.
// Auxiliary Space: O(V)

//  0----1\                   0 : 1 , 4
//  |   /  \                  1 : 0 , 2
//  |  /     2 ------------>  2 : 1 , 3
//  | /    /                  3 : 2 ,  4
//  4----3/                   4 : 0 , 1 ,  3

//DFS : 0 4 3 2 1

//visited = [ 1 , 1 , 1 , 1 , 1]
//stack = [ 1  ]


// Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Auxiliary Space: O(V), since an extra visited array of size V is required.