#include <iostream>
#include <stack>

using namespace std;

class DeQueue
{

    int front = -1;
    int top = -1;
    int size;
    int *arr;

public:
    DeQueue(int d) : size(d) { arr = new int[size]; };

    void push(int data)
    {
        if (isFull())
        {
            cout << "overflow\n";
            return;
        }

        if (top == -1)
        {
            front++;
        }

        arr[++top] = data;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return -1;
        }
        int del = arr[top];

        if (front == top)
        {
            front = top = -1;
        }
        else
        {
            top--;
        }
        return del;
    }

    void insert(int data)
    {
    }
    int remove()
    {

        return -1;
    }

    void show()
    {

        cout << endl;
    };

    // int getFront()
    // {
    //     if (isEmpty())
    //     {
    //         cout << "No element!!\n";
    //         return -1;
    //     }
    //     return front->data;
    // }
    int peek()
    {
        if (isEmpty())
        {
            cout << "No element!!\n";
            return -1;
        }
        return s1.top();
    }

    bool isEmpty()
    {
        return s1.empty();
    }
};

int main()
{
    DeQueue dq;
    dq.push(1);
    dq.push(2);
    dq.push(3);
    dq.push(4);
    // q.push(5);
    // q.push(6);
    // q.push(7);
    dq.show();

    // cout << q.peek() << endl;

    cout << dq.pop() << endl;
    // cout << q.remove() << endl;
    // cout << q.remove() << endl;
    // cout << q.remove() << endl;
    // cout << q.remove() << endl;
    // cout << q.remove() << endl;
    // cout << q.remove() << endl;

    dq.show();

    return 0;
}