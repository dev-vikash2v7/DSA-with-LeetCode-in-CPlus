#include <iostream>
using namespace std;

#define show(message) cout << message << endl

class Node
{
public:
    int data;
    Node *next = NULL;
    Node(int d) : data(d){};
};

class CircularList
{

public:
    Node *head = NULL;

    CircularList(Node *start)
    {
        head = start;
        head->next = head;
    };

    void print(Node *start)
    {
        if (start == NULL)
        {
            cout << "no Nodes available\n";
            return;
        }
        do
        {
            cout << start->data << "->";
            start = start->next;

        } while (start != head);

        cout << "head " << endl;
    }

    void insert_at_End(Node *&head, int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
            head->next = head;
            return;
        }

        Node *node = new Node(data);
        Node *start = head;

        while (start->next != head)
        {
            start = start->next;
        }
        start->next = node;
        node->next = head;
    }

    int delete_Begin(Node *&head)
    {
        Node *start = head;

        if (start == NULL)
        {
            cout << "No Node\n";
            return -1;
        }

        while (start->next != head)
        {
            start = start->next;
        }
        
        Node *deleteNode = head;
        int data = deleteNode->data;

       
        start->next = head->next ; 
        head = head->next;

        delete deleteNode;
        return data;
    }

    int delete_End(Node *&head)
    {
        Node *start = head;

        if (start == NULL)
        {
            cout << "No Node\n";
            return -1;
        }
        if (start->next == start)
        {
            return delete_Begin(head);
        }

        while (start && start->next && start->next->next != head)
        {
            start = start->next;
        }
        Node *deleteNode = start->next;
        int data = deleteNode->data;
        start->next = head;
        delete deleteNode;
        return data;
    }

    int delete_at(Node *head, int pos)
    {
        // Node *temp =
        if (head == NULL)
        {
            return -1;
        }

        if (pos == 0)
        {
            return delete_Begin(head);
        }
        
        Node *start = head;

        while (start->next !=head  && pos != 1)
        {
            start  = start->next;
            pos--;
        }

        Node *todelete = start->next;
        int item = todelete->data;
        start->next = todelete->next;

        delete todelete;

        return item;
    }
};

int main()
{
    Node *head = new Node(1);

    CircularList cl(head);

    cl.insert_at_End(head, 4);
    cl.insert_at_End(head, 9);
    cl.insert_at_End(head, 10);
    cl.insert_at_End(head, 11);

    cl.print(head);

    // cout << "deleted node " << cl.delete_End(head) << endl;
    // cout << "deleted node " << cl.delete_End(head) << endl;
    // cout << "deleted node " << cl.delete_End(head) << endl;
    // cout << "deleted node " << cl.delete_End(head) << endl;

    // cout << "deleted node " << cl.delete_Begin(head) << endl;
    // cout << "deleted node " << cl.delete_Begin(head) << endl;
    // cout << "deleted node " << cl.delete_Begin(head) << endl;
    // cout << "deleted node " << cl.delete_Begin(head) << endl;

    // cout << "deleted node " << cl.delete_at(head , 0) << endl;
    cout << "deleted node " << cl.delete_at(head , 1) << endl;
    cout << "deleted node " << cl.delete_at(head , 2) << endl;
    cout << "deleted node " << cl.delete_at(head , 3) << endl;


    // cl.insert_at_End(head, 4);
    // cl.insert_at_End(head, 9);
    // cl.insert_at_End(head, 10);

    cl.print(head);

    return 0;
}