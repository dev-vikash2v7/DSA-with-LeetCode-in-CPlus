#include <iostream>

using namespace std;

class Stack
{
public:
    int top = -1;
    int *stack;
    int max_size;

    Stack(int size)
    {
        stack = new int[size];
        max_size = size;
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "overfloq!!!!!";
            return;
        }
        stack[++top] = data;
    };

    int pop()
    {
        if (isEmpty())
        {
            cout << "underfloq !!!!!";
            return -1;
        }
        int d = stack[top];

        // delete (queue + front);

        top--;

        return d;
    };

    int getTop()
    {
        if (top == -1)
        {
            return -1;
        }
        return stack[top];
    }

    void show()
    {
        if (isEmpty())
        {
            cout << "no data\n";
            return;
        }
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top + 1 == max_size;
    }
};

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
        visited[i] = 1;
        Stack s(7);
        s.push(i);

        while (!s.isEmpty())
        {

            int v = s.pop();

            for (int j = 0; j < 7; j++)
            {
                if (graph[v][j] == 1 && visited[j] == 0)
                {
                    cout << j << " ";
                    s.push(j);
                    visited[j] = 1;
                }
            }
        }
        // cout << endl;
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
                    cout << j << " , ";
                }
            }
            cout << " }\n";
        }
    }
};

int main()
{

    Graph G;

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