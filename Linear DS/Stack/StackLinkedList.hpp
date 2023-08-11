#include <iostream>
using namespace std;

#define show(message) cout << #message << endl
class StackLinkedList;

/////////////////////////////////////////////////////class List Node ///////////////////////////////////////////////////

class Node
{
public:
    int data;
    Node *next = NULL;
    friend class StackLinkedList;
};

///////////////////////////////////////////////////// class Linked List ///////////////////////////////////////////////////
class StackLinkedList
{
public:
    int length = 0;

    Node *top = NULL;

    StackLinkedList() ;
    

    void display();
    int count_length(Node *node);
    void clear();
    void copylist(Node *&newlist, Node *&oldlist);

    int peek();
    int push(int data);
    int pop();

    int isEmpty();
    int isFull();

    ~StackLinkedList() { clear(); };
};

//////////////////////////////////copy consructor and operator overloading///////////////////////////////////////////////////

StackLinkedList :: StackLinkedList() {
        top = new Node();
    }; 

void StackLinkedList ::display()
{
    Node *temp = top;
    // cout << "dis\n";
    // cout <<  temp->data << endl ;
    // cout <<   temp->next->data << endl ;
    // cout <<   temp->next->next->data << endl ;


    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}

void StackLinkedList ::clear()
{
    // release_node();
    // top = NULL;
};

int StackLinkedList ::pop()
{
    if (isEmpty())
        return -1;

    Node *temp = top;

    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    int data = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    length--;

    return data;
}

///////////////////////////////////////////////////// insertion ///////////////////////////////////////////////////

int StackLinkedList ::push(int data)
{
    Node *node = new Node();

    if (node == NULL)
    {
        cout << "space fulled!!!!\n";
        return 0;
    }
      node->data = data;
    node->next = NULL;

    if(length==0){
        top= node;
        length++;
        return 1;
    }

    Node *temp = top;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
    length++;
    return 1;
}

int StackLinkedList ::isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

int StackLinkedList ::isFull()
{
    Node *n = new Node();

    if (n == NULL)
        return 1;
    return 0;
}
