#include <iostream>
using namespace std;

#define show(message) cout << #message << endl

template <class Type>
class LinkedList;

// List Node
template <class Type>
struct ListNode
{
    Type data;
    ListNode *next; 
};
// template <class Type>
// class ListNode
// {
// public:
//     Type data;
//     ListNode *next; 
// };
int main()
{
    ListNode<char> *first = new ListNode<char>();
    ListNode<char> *second =  new ListNode<char>();
    ListNode<char> *third =  new ListNode<char>();

    first->data = 'e';
    first->next = second;

    second->data ='f';
    second->next = third;

    third->data = 'h';
    third->next = NULL;

  ListNode<char> *ptr = first;

    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
    // delete [] first;
    // delete [] second;
    // delete [] third;

    return 0;
}
