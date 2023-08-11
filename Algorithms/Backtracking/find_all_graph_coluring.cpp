#include <bits/stdc++.h>

using namespace std;


bool isSafe(int curr_color , int curr_vertex , int numVertices , const vector<vector<int>>& graph, vector<int>& color){

// check for all vertices
for(int adj_vertex = 0 ; adj_vertex < numVertices ; adj_vertex++){

        // if vertex is  adjancent to curr_vertex and both have same color then choice of color for vertex is not hold 
        if( graph[adj_vertex][curr_vertex] == 1 && curr_color == color[adj_vertex] ){
                return false ;
        }
}
return true ;
}

bool colorGraphUtil(int curr_vertex,int numVertices ,  const vector<vector<int>>& graph, vector<int>& color, int maxColors , vector<vector<int>>& all_seq ) {
    // if all vertex are colured  then return 
    if(curr_vertex == numVertices){
        all_seq.push_back(color);
        return true;
    }

    for(int curr_color = 1 ; curr_color <= maxColors ; curr_color++){

            // check if the curr color for vertex is matching the criteria
        if(isSafe(curr_color , curr_vertex ,numVertices ,  graph , color)){

                color[curr_vertex] = curr_color ; //change the color of vertex to curr_color

                // do for same thing for next vertex
                colorGraphUtil(curr_vertex+1 , numVertices  , graph, color, maxColors , all_seq );

                //undo the change
                color[curr_vertex] = 0 ;
        }
    }

    return !all_seq.empty();
}

void colorGraph(const vector<vector<int>>& graph, int maxColors , vector<vector<int>>& all_seq ) {
    int numVertices = graph.size();
    vector<int> color(numVertices, 0);  // Initialize all colors as 0

    if (colorGraphUtil(0, numVertices  , graph, color, maxColors , all_seq)) {
        cout << "Vertex\tColor" << endl;
    } else {
        cout << "No valid coloring exists." << endl;
    }
}









int main()
{
vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int maxColors = 3;

    vector<vector<int>>all_seq  = {}; 
    
    colorGraph(graph, maxColors , all_seq);

    for (auto v : all_seq) {
            for(int i : v){
                cout << i << " - ";
            }
            cout << endl;
        }


return 0;
}