#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
    Node(int d) : data(d){};
};

class CircularList
{

public:
    void print(Node *start)
    {
        Node *head = start;

        if (start == NULL)
        {
            cout << "No Nodes\n";
            return;
        }
        do
        {
            cout << start->data << "->";
            start = start->next;

        } while (start != head);

        cout << "head " << endl;
    }

    Node *insert_at_Begin(Node *head, int data)
    {
        Node *node = new Node(data);

        if (head == NULL)
        {
            node->next = node;
            return node;
        }

        Node *start = head;

        while (start->next != head)
        {
            start = start->next;
        }
        start->next = node;
        node->next = head;

        return node;
    };

    Node *insert_at_End(Node *head, int data)
    {
        if (head == NULL)
            return insert_at_Begin(head, data);

        Node *node = new Node(data);
        Node *start = head;

        while (start->next != head)
        {
            start = start->next;
        }
        start->next = node;
        node->next = head;

        return head;
    }

    void insertAtPos(Node *&head, int data, int pos)
    {
        if (pos == 0)
        {
            insert_at_Begin(head, data);
        }
        Node *start = head;
        Node *node = new Node(data);

        while (start && pos != 1)
        {
            start = start->next;
            pos--;
        }

        node->next = start->next;
        start->next = node;
    }
};

int main()
{
    Node *head = NULL;

    CircularList cl;

    head = cl.insert_at_End(head, 4);
    head = cl.insert_at_End(head, 9);
    head = cl.insert_at_End(head, 10);

    cl.print(head);

    head = cl.insert_at_Begin(head, 14);
    head = cl.insert_at_Begin(head, 19);
    head = cl.insert_at_Begin(head, -29);

    cl.print(head);

    cl.insertAtPos( head , 66 , 1);
    cl.insertAtPos( head , 666 , 2);

    
    return 0;
}