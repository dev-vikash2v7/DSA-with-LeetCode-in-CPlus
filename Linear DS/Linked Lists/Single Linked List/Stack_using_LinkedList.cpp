#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d, Node *n = NULL) : data(d), next(n){};
};

class Stack
{

public:
    Node *top = NULL;

    Stack(Node *head) : top(head){};

    bool isfull()
    {
    }
    bool isempty()
    {
        if (top == NULL)
        {
            cout << "stack is empty\n";
            return true;
        }
        return false;
    }

    void print()
    {
        Node *start = top;

        if (isempty())
        {
            return;
        }

        while (start)
        {
            cout << start->data << " ";
            start = start->next;
        }
        cout << endl;
    }

    void insert(int data)
    {
        Node *node = new Node(data, top);

        if (node == NULL)
        {
            cout << "overflow space\n";
            return;
        }
        top = node;
        cout << "inserted node " << top->data << endl;
    }

    int pop()
    {
        if (isempty())
        {
            return -1;
        }

        Node *deleted_node = top;
        int item = top->data;
        top = top->next;
        delete deleted_node;
        return item;
    }
};

int main()
{
    Node *head = new Node(1);
    Stack s(head);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    s.print();

   cout << "pop item " <<  s.pop() << endl;
   cout << "pop item " <<  s.pop() << endl;
   cout << "pop item " <<  s.pop() << endl;
   cout << "pop item " <<  s.pop() << endl;
s.print();
    return 0;
}