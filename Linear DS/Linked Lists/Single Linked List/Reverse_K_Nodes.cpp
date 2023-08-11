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
            cout << "NULL" << endl;
            return;
        }
        cout << start->data << "->";
        print(start->next);
    }

    Node * reverse(Node * &start)
    {
        if (start == NULL || start->next == NULL) return start;

        Node *rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL ;

        return rest ; 
       
    };
    // void reverse(Node *&start)
    // {
    //     Node *prev = NULL;  // null
    //     Node *curr = start; // 1
    //     Node *nextPtr;

    //     while (curr != NULL)
    //     {
    //         nextPtr = curr->next; // 2 , 3 , , 4 , null
    //         curr->next = prev;    // null  , 1 , 2 , 3
    //         prev = curr;          // 1  , 2  ,  3 , 4
    //         curr = nextPtr;       // 2 , 3 , 4  , null
    //     }

    //     start = prev;
    // };

    Node *Reverse_K_Nodes(Node *head, int k)
    {
        Node *prev = NULL; // null
        Node *curr = head; // 1
        Node *nextPtr;

        int c = 0;

        while (curr != NULL && c < k)
        {
           nextPtr = curr->next; // 2 , 3 ,        , 4 , 5    , 6 null
            curr->next = prev;    // null  , 1     , 2 , 3    ,4   5
            prev = curr;          // 1  , 2        ,  3 , 4    5   6
            curr = nextPtr;       // 2 , 3          , 4  , 5   6   null
            c++;
        }

        if (nextPtr)
        {
            cout << nextPtr->data << endl;
            head->next = Reverse_K_Nodes(nextPtr, k);
            // cout << "head : " << head->data  << " " << head->next->data << endl;
        }

        return prev;
    }

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
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    LinkedList ll(head);

    ll.print(head);

   head =  ll.reverse(head);
    //    head =  ll.Reverse_K_Nodes(head , 2) ;

    ll.print(head);

    return 0;
}

/*
Time complexity => O(n)

*/