#include <iostream>
using namespace std;

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
        if(start == NULL){
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

    void insert_at_Begin(Node * &head, int data)
    {
        Node *node = new Node(data);

        if (head == NULL)
        {
            node->next = node;
            head = node;
            return;
        }
        Node *start = head;

        while (start->next != head)
        {
            start = start->next;
        }
        start->next = node ;
        node->next = head;
        head = node;
        // cout <<start->data << " " <<  start->next->data  << " " << node->next->data << endl ;
    };

    void insert_at_End(Node *&head, int data)
    {
        if (head == NULL)
        {
            insert_at_Begin(head, data);
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

    void insertAtPos(Node* &head , int data ,  int pos){
            if(pos == 0 ){
                insert_at_Begin(head , data) ;
            }
            Node * start = head ;
            Node * node = new Node(data);

            while (start && pos != 1){
                start = start->next ; 
                pos-- ;
            }
            
            node->next = start->next ;
            start->next = node ;
    }
};

int main()
{
    Node *head = new Node(1);

    CircularList cl(head);
    // head->next = new Node(2);
    // head->next->next = new Node(3);
    // head->next->next->next = head;

    cl.insert_at_End(head, 4);
    // cl.insert_at_End(head, 9);
    // cl.insert_at_End(head, 10);

    // cl.insertAtPos( head , 66 , 1);
    // cl.insertAtPos( head , 666 , 2);

    cl.insert_at_Begin(head, 14);
    cl.insert_at_Begin(head, 19);
    // cl.insert_at_Begin(head, -29);

    cl.print(head);

    return 0;
}