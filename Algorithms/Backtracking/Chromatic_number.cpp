#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(int vertex, const vector<vector<int>>& graph, const vector<int>& color, int c) {
    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (graph[vertex][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

int getChromaticNumber(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<int> color(numVertices, 0);  // Initialize all colors as 0

    int chromaticNumber = 1;  // Minimum number of colors required

    for (int vertex = 0; vertex < numVertices; ++vertex) {
        for (int c = 1; c <= chromaticNumber; ++c) {
            if (isSafe(vertex, graph, color, c)) {
                color[vertex] = c;
                break;
            }
            if (c == chromaticNumber) {
                chromaticNumber++;  // Increment chromatic number if current number of colors is not enough
            }
        }
    }

    return chromaticNumber;
}

int main() {
    // Example usage:
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int chromaticNumber = getChromaticNumber(graph);

    cout << "Chromatic Number: " << chromaticNumber << endl;

    return 0;
}
