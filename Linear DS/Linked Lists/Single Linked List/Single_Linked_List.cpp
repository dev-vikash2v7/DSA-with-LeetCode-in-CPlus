#include <iostream>
#include "LinkedList.hpp"


int main()
{
    ListNode<int> *head = new ListNode<int>();
    ListNode<int> *second = new ListNode<int>();
    ListNode<int> *third = new ListNode<int>();

    head->data = 35;
    head->next = second;

    second->data = 32;
    second->next = third;

    third->data = 12;
    third->next = NULL;

    LinkedList<int> ptr;
    ptr.root = head;

    ptr.display();
    ptr.count_length(head);

    // ptr.remove_at(0);
    ptr.remove_at_end();
    ptr.remove_at_end();
    // ptr.remove_at_end();
    // ptr.remove_at_end();


    // ptr.display();







    // ptr.insertAtBeggin(25);
    // cout << endl;
    // ptr.insertAtEnd(456);
    // ptr.insertAtEnd(56);

    // ptr.insertAt(3487, 0);
    // ptr.insertAt(1234, 1);
    // ptr.insertAt(4221, 5);

    // ptr.insertAfterNode(second, 343);
    // ptr.display();
    // cout << "length : " << ptr.count_length() << endl;
    // cout << "after clear linked list : \n";

    // ptr.clear();

    // ptr.display();
    // cout << "length : " << ptr.count_length() << endl;

    // ptr.insertAtBeggin(25);
    // ptr.insertAtBeggin(254);
    // ptr.insertAtBeggin(2543);
    // ptr.display();
    // cout << "length : " << ptr.count_length() << endl;

    return 0;
}
