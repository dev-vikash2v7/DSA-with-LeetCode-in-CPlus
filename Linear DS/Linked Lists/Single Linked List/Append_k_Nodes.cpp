#include <iostream>

using namespace std;

struct Node
{
    int data = 0;
    Node *next = NULL;
    Node(int d) : data(d){};
};

class LinkedList
{

public:
    Node *head = NULL;

    LinkedList(Node *start) : head(start){};

    int length(Node *start)
    {
        if (start == NULL)
            return 0;
        return 1 + length(start->next);
    }

    void print(Node *start)
    {
        if (start == NULL)
        {
            cout << "NULL" << endl;
            return;
        }
        cout << start->data << "->";
        print(start->next);
    }

    void append_k_node(Node *&start, int k)
    {
        Node *newTail = NULL;
        Node *newHead = NULL;
        Node *tail = start;

        int c = 1;
        int len = length(start);
        k = k % len;

        while (tail->next)
        {
            if (c == len - k)
            {
                newTail = tail;
                newHead = tail->next;
            }
            tail = tail->next;
            c += 1;
        }

        // cout << newHead->data << endl;
        // cout << tail->data << endl;
        // cout << newTail->data << endl;

        newTail->next = NULL;
        tail->next = start;
        start = newHead;
    }
};

int main()
{

    Node *head = new Node(1);

    LinkedList ll(head);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    ll.print(head);

    ll.append_k_node(head, 3);

    ll.print(head);
    return 0;
}
/*
list = 1,2,3,4,5,6
append first 3 nodes in last
newlist = 4 , 5 , 6 , 1 , 2, 3
*/