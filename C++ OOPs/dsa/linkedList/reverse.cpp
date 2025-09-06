#include <iostream>
#include <vector>
using namespace std;


class Node {
    public:
    Node *next  ;
    int data  ;

    Node(int data  ) : data(data) , next(nullptr){}
};

class LinkedList {
  Node *head  = nullptr; 

    public:

    void insertAtEnd(int data){

        Node* node = new Node(data );

        if(head == nullptr){
            head  = node;
        }
        else{

             Node *temp = head ;

               while (temp->next != nullptr)
                        temp = temp->next;
                        
            temp->next = node;


        }
    }
  
    void display(){

        Node *temp = head ;

        while (temp != nullptr)
        {
            cout << temp->data << " " ;
            temp = temp->next;
        }
        cout <<endl;
        
    }
    void reverse(){

        Node *curr  = head ;
        Node *next  = head->next ;
        curr->next = nullptr ;


        while (next != nullptr)
        {
            Node *temp = next->next ;
            next->next = curr ;

            curr = next;
            next = temp;
          
        }

        head = curr;
        
    }


};
int main()
{
    LinkedList l1;

    l1.insertAtEnd(3);
    l1.insertAtEnd(5);
    l1.insertAtEnd(7);

    
    l1.display();
   

l1.reverse();
    l1.display();




    return 0;
}