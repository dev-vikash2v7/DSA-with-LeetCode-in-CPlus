#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node *next = NULL;
    Node(int d) { data = d; }
};

class LinkedList
{

public:
    Node *head = NULL;
    LinkedList(Node *start)
    {
        head = start;
    };

    void print(Node *start)
    {
        if (start == NULL)
        {
            cout << endl;
            return;
        }
        cout << start->data << " ";
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

    void insert_begin(Node *&start, int data)
    {
        Node *node = new Node(data);
        node->next = start;
        start = node;
    };

    int delete_end(Node *&start)
    {
        if (start == NULL)
        {
            cout << "underflow\n";
            return -1;
        }
        // only one node
        if (start->next == NULL)
        {
            int temp_data = start->data;
            Node *temp = start;
            start = NULL;

            delete temp;
            return temp_data;
        }

        if (start->next->next == NULL)
        {
            int temp_data = start->next->data;
            Node *temp = start->next;

            start->next = NULL;

            delete temp;
            return temp_data;
        }

        delete_end(start->next);
    }

    int delete_begin(Node *&start)
    {
        if (start == NULL)
        {
            cout << "underflow\n";
            return -1;
        }

        int temp_data = start->data;
        Node *temp = start;

        start = start->next;

        delete temp;
        return temp_data;
    };

    ~LinkedList()
    {
        delete head;
    }
};

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    LinkedList ll(head);

    ll.print(head);

    // ll.insert_end(  head , 5) ;
    // ll.insert_end(  head , 6) ;
    // ll.insert_end(  head , 7) ;

    // ll.insert_begin(  head , 0) ;
    // ll.insert_begin(  head , -1) ;
    // ll.insert_begin(  head , -2) ;

    cout << "deleted at end : " << ll.delete_end(head) << endl;
    // cout << "deleted at end : " << ll.delete_end(head) << endl;
    // cout << "deleted at end : " << ll.delete_end(head) << endl;
    // cout << "deleted at end : " << ll.delete_end(head) << endl;
    // cout << "deleted at end : " << ll.delete_end(head) << endl;

    //    cout <<"deleted at begin "  <<  ll.delete_begin(head) << endl;
    //    cout <<"deleted at begin "  <<  ll.delete_begin(head) << endl;
    //    cout <<"deleted at begin "  <<  ll.delete_begin(head) << endl;
    //    cout <<"deleted at begin "  <<  ll.delete_begin(head) << endl;

    ll.print(head);

    return 0;
}