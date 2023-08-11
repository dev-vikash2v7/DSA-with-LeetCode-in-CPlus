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

    int length()
    {
        Node *start = head;
        int len = 0;

        while (start)
        {
            len++;
            start = start->next;
        }

        return len;
    }
};

int find_Intersection(LinkedList l1, LinkedList l2)
{
    int len1 = l1.length();
    int len2 = l2.length();
    cout << len1 << " " << len2 << endl;

    int diff = abs(len1 - len2);

    Node *long_ptr = len1 > len2 ? l1.head : l2.head;
    Node *short_ptr = len1 < len2 ? l1.head : l2.head;

    cout << long_ptr->data << " " << short_ptr->data << endl;

    while (diff > 0)
    {
        diff--;
        long_ptr = long_ptr->next;
        if (!long_ptr)
        {
            return -1;
        }
    }

    while (long_ptr && short_ptr )
    {
        if( long_ptr == short_ptr){
             return long_ptr->data;
        }
        long_ptr = long_ptr->next;
        short_ptr = short_ptr->next;
    }
    // cout << long_ptr->data << " " << short_ptr->data  << endl;

    return -1;
};


void intersect(Node *&head1 , Node* &head2 , int pos){
    Node *temp1 = head1 ;
    pos--;
    while(pos--){
        temp1 = temp1->next ;
    }
    Node *temp2 = head2 ;

      while(temp2->next ){
        temp2 = temp2->next ;
    }

     temp2->next = temp1 ;
}



int main()
{

    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    Node *head2 = new Node(9);
    head2->next = new Node(10);
    head2->next->next = new Node(5);
    head2->next->next->next = new Node(6);

    head1->next->next->next->next = head2->next->next;

    LinkedList l1(head1);
    LinkedList l2(head2);

    l1.print(head1);
    l2.print(head2);

    cout << find_Intersection(l1, l2) << endl;

    return 0;
}
/*
list = 1,2,3,4,5,6
append first 3 nodes in last
newlist = 4 , 5 , 6 , 1 , 2, 3
*/