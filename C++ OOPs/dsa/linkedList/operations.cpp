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
    void insertAtBegin(int data){

        Node* node = new Node(data );

        if(head == nullptr){
            head  = node;
        }
        else{

node->next = head ;
head = node ;


        }
    }

      void insertAtPosition(int data , int pos){

        if (pos < 0) {
            cout << "Position should be >= 0." << endl;
            return;
        }

        Node* node = new Node(data );

        if(head == nullptr){
            head  = node;
        }
        else{
            if(pos == 0){
                insertAtBegin(data);
                return;
            }

            Node *temp = head ;

            while (pos != 1)
            {
                pos--;
                temp = temp->next;
            }
            if(!temp){
            cout << "Position out of range." << endl;
            delete node;
            return;
            }

           Node *next =  temp->next ;

           temp->next = node;
           node->next = next ; 
            
        }
    }


 void deleteFromBegining( ){

if(!head){
    cout <<"List is empty" <<endl;
    return ;
}
    Node *temp = head ;

    head = head->next;

    delete temp;

 }
 void deleteFromEnd( ){

if(!head){
    cout <<"List is empty" <<endl;
    return ;
}
    Node *temp = head ;

//single element;
    if(temp->next == nullptr){
        deleteFromBegining();
        return;
    }

// Traverse to the second-to-last node
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
temp->next = nullptr ; 

 }


 void deleteFromPos(int pos ){

if(!head){
    cout <<"List is empty" <<endl;
    return ;
}

if(pos == 0 ) {
    deleteFromBegining();
    return ; 
}
    Node *temp = head ;

while (pos != 1)
{
    pos--;
    temp = temp->next;
    
}
if(temp->next == nullptr){
    cout << "Index out of range" << endl;
    return ;
}

Node *todeleted = temp->next;

temp->next = todeleted->next;

delete todeleted;



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
  


};
int main()
{
    LinkedList l1;

    l1.insertAtEnd(3);
    l1.insertAtEnd(5);
    l1.insertAtEnd(7);

    l1.insertAtBegin(798);
    l1.insertAtEnd(59);
    l1.insertAtBegin(73);

    l1.insertAtBegin(75);


    // l1.display();

    l1.insertAtPosition(113 , 7);

    // l1.display();

    // l1.deleteFromBegining();
    // l1.display();

    // l1.deleteFromBegining();

    // l1.display();

    
    // l1.deleteFromEnd();
    // l1.display();

    // l1.deleteFromEnd();

    l1.display();

    l1.deleteFromPos(8);

    l1.display();




    return 0;
}