#include <iostream>
using namespace std;
class DLinkedList;

class LinkedNode
{
public:
    int data;
    LinkedNode *next = NULL;
    LinkedNode *prev = NULL;
    friend class DLinkedList;
};

class DLinkedList
{
public:
    DLinkedList(){};
    LinkedNode *root = NULL;
    int length;

    void show(LinkedNode *);
    LinkedNode *insert_at(int pos, int data, LinkedNode *);
    LinkedNode *insert_at_begin(int data, LinkedNode *);
    LinkedNode *delete_at(int pos, LinkedNode *);
    LinkedNode *clear(LinkedNode *);
    int find_item(int data, LinkedNode *);
    int Length(LinkedNode *);

    ~DLinkedList()
    {
        clear(root);
        root = NULL;
    }
};

void DLinkedList ::show(LinkedNode *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        show(node->next);
    }
};

LinkedNode *DLinkedList ::insert_at_begin(int data, LinkedNode *node)
{

    LinkedNode *head = new LinkedNode();
    node->prev = head;
    head->data = data;
    head->next = node;
    head->prev = NULL;

    root = head;
    return head;
};

LinkedNode *DLinkedList ::insert_at(int pos, int data, LinkedNode *node)
{

    if (pos == 0)
    {
        return insert_at_begin(data, node);
    }
    else if (pos == 1)
    {
        LinkedNode *temp = new LinkedNode();
        temp->data = data;
        temp->next = node->next;
        temp->prev = node;
        node->next = temp;
    }
    else
    {
        insert_at(pos - 1, data, node->next);
    }
    root = node;
    return node;
};

LinkedNode *DLinkedList ::delete_at(int pos, LinkedNode *node)
{
    if (pos == 0)
    {
        LinkedNode *temp = node->next;
        temp->prev = NULL;
        free(node);

        root = temp;
        return temp;
    }
    else if (pos == 1)
    {
        LinkedNode *temp = node->next;

        node->next = temp->next;
        temp->next->prev = node;
        free(temp);
    }
    else
    {
        delete_at(pos - 1, node->next);
    }
    root = node;
    return node;
};

LinkedNode *DLinkedList::clear(LinkedNode *node)
{
    if (node != NULL)
    {
        clear(node->next);
        // free(node);
        delete node;
    }
    root = NULL;
    return root;
}

int DLinkedList::find_item(int data, LinkedNode *node)
{
    static int index = 0;
    if (node->data == data && node->next != NULL)
    {
        return index;
    }
    else if (node->next == NULL)
    {
        if (node->data == data)
        {
            return index;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        index++;
        return find_item(data, node->next);
    }
}

int DLinkedList::Length(LinkedNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + Length(node->next);
    }
}

int main()
{
    LinkedNode *head = new LinkedNode();
    LinkedNode *second = new LinkedNode();
    LinkedNode *third = new LinkedNode();
    LinkedNode *fourth = new LinkedNode();

    if (head == NULL || second == NULL || third == NULL || fourth == NULL)
    {
        cout << "space fulled\n";
        exit(0);
    }

    head->prev = NULL;
    head->data = 3;
    head->next = second;

    second->prev = head;
    second->data = 24;
    second->next = third;

    third->prev = second;
    third->data = 423;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 1987;
    fourth->next = NULL;

    DLinkedList ptr;
    ptr.show(head);
    cout << "\n";

    // head = ptr.insert_at(0, 69659, head);
    // head = ptr.insert_at_begin(999, head);

    // head = ptr.clear(head);
    // head = ptr.delete_at(1, head);
    // head = ptr.delete_at(0, head);

    // cout << ptr.find_item(1987, head);
    cout << ptr.Length(head) << endl;
    // ptr.show(head);

    return 0;
}