#include <iostream>

using namespace std;


class Graph
{
    int visited[7] = {0};
    int graph[7][7] = {
        // 0      1       2      3       4     5          6
        {0, 1, 1, 0, 0, 0, 0}, // 0
        {1, 0, 1, 1, 0, 0, 0}, // 1
        {1, 0, 0, 1, 1, 0, 0}, // 2
        {0, 1, 1, 0, 1, 0, 0}, // 3
        {0, 0, 1, 1, 0, 1, 1}, // 4
        {0, 0, 0, 0, 1, 0, 0}, // 5
        {0, 0, 0, 0, 1, 0, 0}, // 6
    };

public:
    void DFS(int i)
    {
        cout << i << " ";
        visited[i] = 1;
        for (int j = 0; j < 7; j++)
        {
            if (graph[i][j] == 1 && visited[j] == 0)
            {
                DFS(j);
            }
        }
    }

    void showGraph()
    {
        for (int i = 0; i < 7; i++)
        {
            cout << i << " { ";
            for (int j = 0; j < 7; j++)
            {
                if (graph[i][j] == 1)
                {
                    cout << j << " ";
                }
            }
            cout << " }\n";
        }
    }
};

int main()
{

    Graph G;

G.showGraph();
    G.DFS(4);

    return 0;
}

/*
   0-----1
   |     |
   2-----3
   \     /
      4
    /   \
   5      6
*/