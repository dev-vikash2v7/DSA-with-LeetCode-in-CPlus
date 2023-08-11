#include <iostream>

using namespace std;

class Queue
{
public:
    int top = -1, front = -1;
    int *queue;
    int max_size;

    Queue(int size)
    {
        queue = new int[size];
        max_size = size;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "overfloq!!!!!";
            return;
        }
        if (front == -1)
        {
            front++;
        }
        queue[++top] = data;
    };

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "underfloq !!!!!";
            return -1;
        }
        int d = queue[front];

        // delete (queue + front);

        if (front == top)
        {
            top = -1;
            front = -1;
        }
        else
        {
            front++;
        }
        return d;
    };
    int getFront()
    {
        if (top == -1)
        {
            return -1;
        }

        return queue[front];
    }
    int getTop()
    {
        if (top == -1)
        {
            return -1;
        }
        return queue[top];
    }

    void show()
    {
        if (isEmpty())
        {
            cout << "no data\n";
            return;
        }
        for (int i = front; i <= top; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return top + 1 == max_size;
    }
};

class Graph
{
public:
    void BFS(int graph[7][7])
    {
        int visited[7] = {0};

        Queue q(8);

        int i = 0;
        cout << i << " ";
        q.enqueue(i);
        visited[i] = 1;

        while (!q.isEmpty())
        {
            int v = q.dequeue();

            for (int j = 0; j < 7; j++)
            {
                if (graph[v][j] == 1 && visited[j] == 0)
                {
                    cout << j << " ";
                    q.enqueue(j);
                    visited[j] = 1;
                }
            }
            cout << endl;
        }
    }

    void showGraph(int graph[7][7])
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

    Graph G;

    G.BFS(graph);

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