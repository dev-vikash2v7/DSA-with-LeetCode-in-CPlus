#include <iostream>
#include <stack>

using namespace std;

class Queue
{

    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int data)
    {
        s1.push(data);
    }

//using stack call
    // int dequeu()
    // {
    //     if (isEmpty())
    //     {
    //         cout << "Queue Underflow!!\n";
    //         return -1;
    //     }
        
    //     int d = s1.top();
    //     s1.pop();

    //     if (s1.empty())
    //     {
    //        return d;
    //     }

    //     int todelete = dequeu();
    //     cout << "item d : " << todelete << " " << d << endl; 
    //     s1.push(d);
    //     return todelete;
    // }
    //using 2 stack
    int dequeu()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue Underflow!!\n";
            return -1;
        }
        if(s2.empty()){
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        }
        int topval = s2.top();
        s2.pop();
        
        return topval;
    }

    void show()
    {
        if (s1.empty())
            return;

        stack<int> s3(s1);
        stack<int> s4(s2);

        while (!s3.empty())
        {
            cout << s3.top() << " ";
            s3.pop();
        }
        while (!s4.empty())
        {
            cout << s4.top() << " ";
            s4.pop();
        }
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
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    // q.enqueue(5);
    // q.enqueue(6);
    // q.enqueue(7);
    q.show();

    // cout << q.peek() << endl;

    cout << q.dequeu() << endl;
    // cout << q.dequeu() << endl;
    // cout << q.dequeu() << endl;
    // cout << q.dequeu() << endl;
    // cout << q.dequeu() << endl;
    // cout << q.dequeu() << endl;
    // cout << q.dequeu() << endl;

    q.show();

    return 0;
}