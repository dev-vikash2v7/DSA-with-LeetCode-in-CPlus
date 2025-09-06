#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> adjList = {
        {1, 3},     // neighbors of node 0
        {0, 2, 3},  // neighbors of node 1
        {1},        // neighbors of node 2
        {0, 1, 4},  // neighbors of node 3
        {3}         // neighbors of node 4
    };

    cout << "BFS traversal starting from node 0: ";
    bfs(0, adjList);
    cout << endl;

    return 0;
}
