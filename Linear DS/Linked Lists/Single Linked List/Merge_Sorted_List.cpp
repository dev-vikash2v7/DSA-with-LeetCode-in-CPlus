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
};

Node *mergeSortedList(LinkedList l1, LinkedList l2)
{
    Node *head1 = l1.head;
    Node *head2 = l2.head;

    Node *dummyNode = new Node(-1);
    Node *mergeNode = dummyNode;

    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            mergeNode->next = head1;
            head1 = head1->next;
        }
        else
        {
            mergeNode->next = head2;
            head2 = head2->next;
        }
        mergeNode = mergeNode->next;
    }
    while (head1)
    {
        mergeNode->next = head1;
        head1 = head1->next;
        mergeNode = mergeNode->next;
    }

    while (head2)
    {
        mergeNode->next = head2;
        head2 = head2->next;
        mergeNode = mergeNode->next;
    }
    return dummyNode->next;
}

Node *MergeRecursive(Node *head1, Node *head2)
{
    if (! head1){
        return head2;
    }
    if(! head2){
        return head1 ;
    }

    Node *result;

    if (head1->data < head2->data)
    {
        result = head1;
        result->next = MergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = MergeRecursive(head1, head2->next);
    }

    return result;
}
int main()
{

    Node *head1 = new Node(1);

    LinkedList l1(head1);
    l1.insert_end(head1, 4);
    l1.insert_end(head1, 9);

    Node *head2 = new Node(3);

    LinkedList l2(head2);

    l2.insert_end(head2, 4);
    l2.insert_end(head2, 7);
    l2.insert_end(head2, 8);

    l1.print(head1);
    l2.print(head2);

    Node *mergeNode = mergeSortedList(l1, l2);
    // Node *mergeNode = MergeRecursive (l1.head, l2.head);

    LinkedList mergeList(mergeNode);
    mergeList.print(mergeNode);
}