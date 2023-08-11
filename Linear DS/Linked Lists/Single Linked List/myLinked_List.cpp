#include <iostream>
using namespace std;

#define show(message) cout << message << endl

class LinkedList;

/////////////////////////////////////////////////////class List Node ///////////////////////////////////////////////////

class Node
{
public:
    int data;
    Node *next;
    friend class LinkedList;
};

///////////////////////////////////////////////////// class Linked List ///////////////////////////////////////////////////
class LinkedList
{
public:
    int length = 0;

    Node *root = NULL;
    LinkedList(){};                            // default constructor
    LinkedList(const LinkedList &);            // copy constructor
    LinkedList &operator=(const LinkedList &); // = operator

    void display(Node *);
    int getItem(int pos, Node *node);
    int count_length(Node *node);
    void clear();
    void copylist(Node *&newlist, Node *&oldlist);
    bool checkRange(int pos);
    void insertAtBegin(int data);
    void insertAtEnd(int data);
    void insertAt(int data, int pos, Node *&node);
    void insertAfterNode(Node *prevNode, int data);

    void remove_at(int pos, Node *&node);
    void remove_at_end();
    void remove_at_value(int value, Node *&node);
    void release_node(Node *&node);

    ~LinkedList() { release_node(root); };
};

//////////////////////////////////copy consructor and operator overloading//////////////////////////////////////////////////

///////////////////////////////////////////////////// retrival ///////////////////////////////////////////////////

bool LinkedList ::checkRange(int pos)
{
    if (pos < length && pos >= 0)
    {
        return true;
    }
    else
    {
        show("index out of range\n");
        return false;
    }
};
int LinkedList ::getItem(int pos, Node *node)
{
    if (pos == 0)
    {
        return node->data;
    }
    else
    {
        return getItem(pos - 1, node->next);
    }
};

void LinkedList::display(Node *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        display(node->next);
    }
    else
    {
        cout << endl;
    }
}

int LinkedList::count_length(Node *node)
{
    if (node != NULL)
    {
        length = 1 + count_length(node->next);
        // cout << length << endl;
        return length;
    }
    return 0;
}

///////////////////////////////////////////////////// deletion ///////////////////////////////////////////////////

void LinkedList::clear()
{
    release_node(root);
    root = NULL;
};

void LinkedList::remove_at(int pos, Node *&node)
{
    if (checkRange(pos))
    {

        if (pos == 1)
        {
            Node *ptr = node->next;
            node->next = ptr->next;
            free(ptr);
        }
        else if (pos == 0)
        {
            Node *ptr = root;
            root = root->next;
            free(ptr);
        }
        else
        {
            remove_at(pos - 1, node->next);
        }
    }
}

void LinkedList::remove_at_end()
{
    Node *ptr = root;
    Node *lastNode = root->next; // last_elemt

    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(lastNode);
}

void LinkedList::remove_at_value(int value, Node *&node)
{
    Node *ptr = node;
    Node *temp = node->next;

    while (temp->data != value && temp->next != NULL)
    {
       ptr = ptr->next;
        temp = temp->next;
    }
    if (temp->data == value)
    {
        ptr->next = temp->next;
                free(temp);

    }
  
}

void LinkedList::release_node(Node *&node)
{
    if (node != NULL)
    {
        release_node(node->next);
        delete node;
    }
}

///////////////////////////////////////////////////// insertion ///////////////////////////////////////////////////

void LinkedList::insertAtBegin(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = root;
    root = temp;
}

void LinkedList::insertAtEnd(int data)
{
}

void LinkedList::insertAfterNode(Node *prevNode, int data)
{
}

void LinkedList::insertAt(int data, int pos, Node *&node)
{
    if (checkRange(pos))
    {
        if (pos == 0)
        {
            Node *temp = new Node();
            temp->data = data;
            temp->next = node;
            node = temp;
        }
        else
        {
            insertAt(data, pos - 1, node->next);
        }
    }
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 35;
    head->next = second;

    second->data = 32;
    second->next = third;

    third->data = 12;
    third->next = NULL;

    LinkedList ptr;
    ptr.root = head;
    ptr.count_length(ptr.root);

    ptr.display(ptr.root);
    // ptr.clear();
    // ptr.insertAt(567, 1, ptr.root);
    // ptr.insertAtBegin(456);

    // ptr.remove_at(1, ptr.root);
    // ptr.remove_at(0, ptr.root);
    // ptr.remove_at_end();
    ptr.remove_at_value(12, ptr.root);
    ptr.display(ptr.root);

    // cout << ptr.getItem(1,ptr.root);

    return 0;
}