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

    void insert_end(Node *start, int data)
    {
        if (start == NULL)
            return;

        if (start->next == NULL)
        {
            start->next = new Node(data);
            return;
        }
        insert_end(start->next, data);
    }

    // floyd's algorithm
    Node *Cycle_Detection(Node *start)
    {
        Node *turtle = start;
        Node *rabbit = start->next;

        while (rabbit && rabbit->next)
        {
            // cout << turtle->data<<"  -> ";
            if (turtle == rabbit)
            {
                return turtle;
            }
            turtle = turtle->next;
            rabbit = rabbit->next->next;
        }

        return 0;
    }

    void Cycle_Removal(Node *&start)
    {
        Node *turtle = start;
        Node *rabbit = start;

        do
        {
            turtle = turtle->next;
            rabbit = rabbit->next->next;
        } while (turtle != rabbit);

        rabbit = start;

        while (rabbit->next != turtle->next)
        {
            turtle = turtle->next;
            rabbit = rabbit->next;
        };
        rabbit->next = NULL;
    };

    void makeCycle(Node *start, int pos)
    {
        Node *cycleNode = NULL;

        while (start->next)
        {
            if (pos == 0)
            {
                cycleNode = start;
            }
            start = start->next;
            pos--;
        }

        start->next = cycleNode;
    }

    void isCycle(Node *head)
    {
        if (Cycle_Detection(head))
        {
            cout << "it has cycle\n";
            Cycle_Removal(head);
        }
        else
        {
            cout << "No cycle\n";
            print(head);
        }
    }
};

int main()
{

    Node *head = new Node(1);

    LinkedList ll(head);

    ll.insert_end(head, 2);
    ll.insert_end(head, 3);
    ll.insert_end(head, 4);
    ll.insert_end(head, 5);
    ll.insert_end(head, 6);
    ll.insert_end(head, 7);
    ll.insert_end(head, 8);

    // 1   2     3     4      5     6       7   8     null        1   2     3
    // head->next->next->next->next->next->next->next->next = head->next; // 6 - 2

    // ll.make_cycle(head , )
    ll.makeCycle(head, 4);

    ll.isCycle(head);
    ll.Cycle_Removal(head);
    ll.print(head);
    // ll.isCycle(head);

    return 0;
}

/*
list = 1,2,3,4,5,6, 7 ,8

*/