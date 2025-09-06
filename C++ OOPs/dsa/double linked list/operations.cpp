#include <iostream>
#include <vector>
using namespace std;


class Node {
    public:
    Node *next  ;
    Node *prev  ;
    int data  ;

    Node(int data  ) : data(data) , next(nullptr)  , prev(nullptr){}
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
            node->prev = temp;


        }
    }
    void insertAtBegin(int data){

        Node* node = new Node(data );

        if(head == nullptr){
            head  = node;
        }
        else{

head->prev = node;
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

            if(!temp->next){
                temp->next = node ;
                node->prev = temp;
                return ;
            }

           node->next = temp->next  ; 

            node->prev = temp;

           temp->next->prev = node ;

           temp->next = node;
           
            
        }
    }


 void deleteFromBegining( ){

if(!head){
    cout <<"List is empty" <<endl;
    return ;
}
    Node *temp = head ;


    head = head->next;

    if(head)        head->prev = nullptr;

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
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->prev->next = nullptr ;
    delete temp;

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
    
if(!temp || !temp->next){
    cout << "Index out of range" << endl;
    return ;
}
}

cout << temp->data <<endl;

Node *todeleted = temp->next;

if(!todeleted->next){
    temp->next = nullptr;
}
else{
todeleted->next->prev = temp;
temp->next = todeleted->next;
}



delete todeleted;



 }

 void deletedKey(int key){

    Node *temp = head;



while (key != temp->data)
{
    temp = temp->next; 

    if(!temp){
        cout << "Item is not present" << endl;
        return;
    }

}

//only 1
if(!temp->next && !temp->prev   ){
    head = nullptr;
    delete temp ;
    return;
}

// first element
else if(!temp->prev){
    temp->next->prev = nullptr;
    head = temp->next;
    delete temp ;
    return;
}

//last
else if(temp->prev && !temp->next ){
    temp->prev->next = nullptr;
    delete temp ;
    return;
}


    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;




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
    void printReverse(){

        Node *temp = head ;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        while (temp != nullptr)
        {
            cout << temp->data << " " ;
            temp = temp->prev;
        }
        cout <<endl;
        
    }
  


};
int main()
{
    LinkedList l1;

    l1.insertAtEnd(3);
    // l1.insertAtEnd(5);
    // l1.insertAtEnd(7);

    // l1.insertAtBegin(798);
    // l1.insertAtEnd(59);
    // l1.insertAtBegin(73);

    // l1.insertAtBegin(75);


    l1.display();

    // l1.insertAtPosition(113 , 1);


    // l1.deleteFromBegining();

    // l1.deleteFromBegining();

    
    // l1.deleteFromEnd();
    // l1.display();

    // l1.deleteFromEnd();

    // l1.display();
    // l1.printReverse();

    // l1.deleteFromPos(1);
    l1.deletedKey(3);

    l1.display();

    l1.printReverse();



    return 0;
}