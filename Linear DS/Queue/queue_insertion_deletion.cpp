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
        if (top + 1 == max_size)
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
        if (front == -1)
        {
            cout << "underfloq !!!!!";
            return -1;
        }
        cout << "front " << front << endl;
        int d = queue[front];

        // delete (queue+front) ;

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
        if (front == -1)
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
};


int main()
{

 
    Queue q(7);

    // cout << q.getFront() << endl;
    // cout << q.getTop() << endl;

    q.enqueue(54);
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(1);

    cout << q.dequeue() << endl;
    ;
    cout << q.dequeue() << endl;
    ;
    cout << q.dequeue() << endl;
    ;
    cout << q.dequeue() << endl;
    ;

    // cout << q.getFront() << endl;
    // cout << q.getTop() << endl;

    // q.enqueue(15);
    // q.enqueue(1);

    q.show();

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