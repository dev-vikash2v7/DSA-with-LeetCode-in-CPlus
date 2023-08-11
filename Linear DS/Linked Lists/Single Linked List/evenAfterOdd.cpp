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

    void insert_end(Node *&start, int data)
    {
        if (start == NULL)
        {
            start = new Node(data);
            return;
        }

        if (start->next == NULL)
        {
            start->next = new Node(data);
            return;
        }
        insert_end(start->next, data);
    }

    void evenAfterOdd(Node *head)
    {
        if (head == NULL)
            return;

        Node *odd = head;
        Node *evenStart = head->next;
        Node *even = evenStart;

        while (odd->next && even->next)
        {

            odd->next = even->next;
            odd = even->next;

            even->next = odd->next;
            even = odd->next;
        }

        cout << odd->data << endl;

        if (even)
        {
            even->next = NULL;
            cout << even->data << endl;
        }

        odd->next = evenStart ;
        // even->next = NULL ;
    }
};
int main()
{

    Node *head = NULL;

    LinkedList ll;

    ll.insert_end(head, 1);
    ll.insert_end(head, 2);
    ll.insert_end(head, 3);
    ll.insert_end(head, 4);
    ll.insert_end(head, 5);
    ll.insert_end(head, 6);
    ll.insert_end(head, 7);
    ll.insert_end(head, 8);
    ll.print(head);

    ll.evenAfterOdd(head);

    ll.print(head);

    return 0;
}

// 1 2 3 4 5 6 7 8
// 1 3 5 7 | 2 4 6 8